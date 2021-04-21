#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int dieSimulator(int n, vector<int>& rollMax) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(6, vector<int>(16)));
    return helper(n, -1, 0, rollMax, dp);
  }

  int helper(int n, int last, int curlen, vector<int>& rollMax, vector<vector<vector<int>>>& dp) {
    if (n == 0) return 1;
    if (last >= 0 && dp[n][last][curlen] > 0) return dp[n][last][curlen];
    int res = 0;
    for (int i = 0; i < 6; ++i) {
      if (last == i && curlen == rollMax[i]) {
        continue;
      }
      res = (res + helper(n - 1, i, i == last ? curlen + 1 : 1, rollMax, dp)) % mod;
    }
    if (last != -1) dp[n][last][curlen] = res;
    return res;
  }

  static const int mod = 1e9 + 7;
};

int main() {
  int n;
  cin >> n;
  vector<int> rollMax(6);
  for (int i = 0; i < 6; ++i) cin >> rollMax[i];
  Solution s;
  cout << s.dieSimulator(n, rollMax) << endl;
  return 0;
}