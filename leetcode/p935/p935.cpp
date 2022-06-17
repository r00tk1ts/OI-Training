#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int knightDialer(int n) {
    const int mod = 1e9 + 7;
    vector<pair<int, int>> offset{
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(4, vector<int>(3)));
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i == 3 && j == 0 || i == 3 && j == 2)
          dp[1][i][j] = 0;
        else
          dp[1][i][j] = 1;
      }
    }

    for (int t = 2; t <= n; ++t) {
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
          for (auto& p : offset) {
            int x = i + p.first;
            int y = j + p.second;
            if (x == 3 && (y == 0 || y == 2)) continue;
            if (0 <= x && x <= 3 && 0 <= y && y <= 2) {
              dp[t][i][j] = (dp[t][i][j] + dp[t - 1][x][y]) % mod;
            }
          }
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i == 3 && (j == 0 || j == 2)) continue;
        sum = (sum + dp[n][i][j]) % mod;
      }
    }
    return sum;
  }
};

int main() {
  int n;
  cin >> n;
  Solution s;
  cout << s.knightDialer(n) << endl;
  return 0;
}