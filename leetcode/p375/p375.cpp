#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(1, n, dp);
  }
  int helper(int left, int right, vector<vector<int>>& dp) {
    if (left >= right) return 0;
    if (left + 1 == right) return left;
    if (dp[left][right] != -1) return dp[left][right];
    int ans = INT_MAX;
    for (int k = left; k <= right; ++k) {
      ans = min(ans, k + max(helper(left, k - 1, dp), helper(k + 1, right, dp)));
    }
    return dp[left][right] = ans;
  }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().getMoneyAmount(n) << endl;
  return 0;
}