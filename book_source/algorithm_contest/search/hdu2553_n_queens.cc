#include <iostream>
#include <math.h>
#include <memory.h>

using namespace std;

int n, tot = 0;
int col[12] = {0};

bool check(int c, int r) {
  for (int i = 0; i < r; ++i) {
    if (col[i] == c || (abs(col[i] - c) == abs(i - r)))
      return false;
  }
  return true;
}

void DFS(int r) {
  if (r == n) {
    tot++;
    return;
  }
  for (int c = 0; c < n; ++c) {
    if (check(c, r)) {
      col[r] = c;
      DFS(r + 1);
    }
  }
}

int main() {
  int ans[12] = {0};
  for (n = 0; n <= 10; ++n) {
    memset(col, 0, sizeof(col));
    tot = 0;
    DFS(0);
    ans[n] = tot;
  }
  while (cin >> n) {
    if (n == 0)
      return 0;
    cout << ans[n] << endl;
  }
  return 0;
}