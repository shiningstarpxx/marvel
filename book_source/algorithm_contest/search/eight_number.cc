#include <memory.h>

#include <iostream>
#include <queue>

using namespace std;

long Cantor(int str[], int n) {
  static long int factory[] = {1,   1,   2,    6,     24,
                               120, 720, 5040, 40320, 362880};  // (0 ~ 9)!

  long result = 0;
  for (int i = 0; i < n; ++i) {
    int counted = 0;
    for (int j = i + 1; j < n; ++j) {
      if (str[i] > str[j]) ++counted;
    }
    result += counted * factory[n - i - 1];
  }
  return result;
}

const int LEN = 362880;
int visited[LEN] = {0};

bool CalCantorAndCache(int str[], int n) {
  long result = Cantor(str, n);
  if (!visited[result]) {
    visited[result] = 1;
    return true;
  }
  return false;
}

struct Node {
  /* data */
  int state[9];
  int dis;
};

int start[9];
int goal[9];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs() {
  Node head;
  memcpy(head.state, start, sizeof(head.state));
  head.dis = 0;
  queue<Node> q;
  q.push(head);

  while (!q.empty()) {
    head = q.front();
    q.pop();
    int z;
    for (z = 0; z < 9; ++z) {  // 找到这个状态中0的位置，也就是可以移动的位置
      if (head.state[z] == 0) break;
    }

    int x = z % 3;
    int y = z / 3;

    for (int i = 0; i < 4; i++) {
      int new_x = x + dir[i][0];
      int new_y = y + dir[i][1];
      if (new_x >= 0 && new_x < 3 && new_y >= 0 && new_y < 3) {
        int new_z = new_x + 3 * new_y;
        Node t;
        memcpy(&t, &head, sizeof(struct Node));
        swap(t.state[new_z], t.state[z]);  // 移动0的位置
        t.dis++;
        if (memcmp(t.state, goal, sizeof(goal)) == 0) return t.dis;
        if (CalCantorAndCache(t.state, 9))
          q.push(t);  // 新状态，就放入队列做扩展
      }
    }
  }
  return -1;
}

int main() {
  for (int i = 0; i < 9; ++i) cin >> start[i];
  for (int i = 0; i < 9; ++i) cin >> goal[i];
  int num = bfs();
  if (num != -1)
    cout << num << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}