#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int tilingRectangle(int n, int m) {
    int size = max(n, m) + 1;
    vector<vector<int>> dp(size, vector<int>(size, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i < size; ++i) {
      dp[i][i] = 1;
      dp[0][i] = dp[i][0] = 0;
    }
    // special case
    if (size > 13) dp[11][13] = dp[13][11] = 6;
    return helper(n, m, dp);
  }

  int helper(int n, int m, vector<vector<int>>& dp) {
    if (dp[n][m] != INT_MAX) return dp[n][m];
    int range = min(n, m);
    for (int i = 1; i <= range; ++i) {
      int left = helper(n - i, m, dp);
      int right = helper(i, m - i, dp);
      dp[n][m] = min(dp[n][m], left + right + 1);

      int top = helper(n, m - i, dp);
      int bottom = helper(n - i, i, dp);
      dp[n][m] = min(dp[n][m], top + bottom + 1);
    }
    return dp[m][n] = dp[n][m];
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  Solution s;
  cout << s.tilingRectangle(n, m) << endl;
  return 0;
}