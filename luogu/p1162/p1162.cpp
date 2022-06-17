#include <bits/stdc++.h>

using namespace std;

struct Area {
  int value;
  bool flag;

  Area() : value(0), flag(false) {}
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
Area area[32][32];
int n;

void dfs(int x, int y) {
  if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || area[x][y].flag || area[x][y].value == 1) return;
  area[x][y].flag = true;
  for (int i = 0; i < 4; ++i) {
    dfs(x + dx[i], y + dy[i]);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> area[i][j].value;
    }
  }
  dfs(0, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (area[i][j].value == 0 && !area[i][j].flag)
        cout << 2 << ' ';
      else
        cout << area[i][j].value << ' ';
    }
    cout << endl;
  }
  return 0;
}