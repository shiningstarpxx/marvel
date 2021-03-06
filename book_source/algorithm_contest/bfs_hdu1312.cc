/*
Problem Description
There is a rectangular room, covered with square tiles. Each tile is colored
either red or black. A man is standing on a black tile. From a tile, he can move
to one of four adjacent tiles. But he can't move on red tiles, he can move only
on black tiles.

Write a program to count the number of black tiles which he can reach by
repeating the moves described above.

Input
The input consists of multiple data sets. A data set starts with a line
containing two positive integers W and H; W and H are the numbers of tiles in
the x- and y- directions, respectively. W and H are not more than 20.

There are H more lines in the data set, each of which includes W characters.
Each character represents the color of a tile as follows.

'.' - a black tile
'#' - a red tile
'@' - a man on a black tile(appears exactly once in a data set)

Output
For each data set, your program should output a line which contains the number
of tiles he can reach from the initial tile (including itself).
*/

#include <iostream>
#include <queue>

using namespace std;

char room[23][23];

int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int Wx, Hy, num;

#define CHECK(x, y) (x < Wx && x >= 0 && y >= 0 && y < Hy)

struct node {
  int x, y;
};

void BFS(int dx, int dy) {
  num = 1;
  queue<node> q;
  node start, next;
  start.x = dx;
  start.y = dy;
  q.push(start);
  while (!q.empty()) {
    start = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      next.x = start.x + dir[i][0];
      next.y = start.y + dir[i][1];
      if (CHECK(next.x, next.y) && room[next.x][next.y] == '.') {
        room[next.x][next.y] = '#';
        num++;
        q.push(next);
      }
    }
  }
}

int main() {
  int x, y, dx, dy;
  while (cin >> Wx >> Hy) {
    if (Wx == 0 && Hy == 0) break;
    for (x = 0; x < Wx; ++x) {
      for (y = 0; y < Hy; ++y) {
        cin >> room[x][y];
        if (room[x][y] == '@') {
          dx = x;
          dy = y;
        }
      }
    }
    num = 0;
    BFS(dx, dy);
    cout << num << endl;
  }
  return 0;
}