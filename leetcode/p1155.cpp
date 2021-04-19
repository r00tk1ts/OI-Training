#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numRollsToTarget(int d, int f, int target) {
    const int mod = 1e9 + 7;
    vector<vector<int>> dp(d + 1, vector<int>(target + 1));
    for (int i = 1; i <= min(f, target); ++i) {
      dp[1][i] = 1;
    }
    for (int i = 2; i <= d; ++i) {
      for (int t = 1; t <= target; ++t) {
        for (int k = 1; k <= f; ++k) {
          if (t - k > 0) {
            dp[i][t] = (dp[i][t] + dp[i - 1][t - k]) % mod;
          } else {
            break;
          }
        }
      }
    }

    return dp[d][target];
  }
};

int main() {
  int d, f, target;
  cin >> d >> f >> target;
  Solution s;
  cout << s.numRollsToTarget(d, f, target) << endl;
  return 0;
}