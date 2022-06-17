#include <bits/stdc++.h>

using namespace std;

int m, n;
int flag[1000000];
int number[1000000];
char s[1000][1000];

void dfs(int x, int y, int f) {
  if (flag[x * n + y] == f) return;
  flag[x * n + y] = f;
  number[f]++;

  if (x - 1 >= 0 && s[x - 1][y] != s[x][y]) dfs(x - 1, y, f);
  if (x + 1 < n && s[x + 1][y] != s[x][y]) dfs(x + 1, y, f);
  if (y - 1 >= 0 && s[x][y - 1] != s[x][y]) dfs(x, y - 1, f);
  if (y + 1 < n && s[x][y + 1] != s[x][y]) dfs(x, y + 1, f);
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  memset(flag, -1, sizeof(flag));

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (flag[x * n + y] == -1) {
      // 如果没搜过，就用i作为flag，对深搜路过的所有块都标记一下
      dfs(x, y, i);
    } else {
      // 否则此前就已经搜过了（联通块从任一一块开始搜，结果都是一样的，所以没必要重来）
      number[i] = number[flag[x * n + y]];
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << number[i] << endl;
  }
  return 0;
}