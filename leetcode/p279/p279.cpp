#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i - j * j] + 1, dp[i]);
      }
    }

    return dp[n];
  }
};

int main() {
  int n;
  cin >> n;
  Solution s;
  cout << s.numSquares(n) << endl;
  return 0;
}