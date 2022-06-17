#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numWays(int steps, int arrLen) {
    const int mod = 1e9 + 7;
    int effectiveLen = min(steps / 2 + 1, arrLen);
    vector<vector<int>> dp(steps + 1, vector<int>(effectiveLen));
    dp[0][0] = 1;
    for (int i = 1; i <= steps; ++i) {
      for (int j = 0; j < effectiveLen; ++j) {
        if (j >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
        if (j < effectiveLen - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
      }
    }
    return dp[steps][0];
  }
};

int main() {
  int steps, arrLen;
  cin >> steps >> arrLen;
  cout << Solution().numWays(steps, arrLen) << endl;
  return 0;
}