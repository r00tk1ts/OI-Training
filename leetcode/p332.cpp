#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i <= amount; ++i) {
      for (auto coin : coins) {
        if (i >= coin) {
          dp[i] = min(dp[i - coin], dp[i] - 1) + 1;
        }
      }
    }
    if (dp[amount] == INT_MAX) {
      dp[amount] = -1;
    }
    return dp[amount];
  }
};

int main() {
  int m, n;
  cin >> m >> n;

  vector<int> coins(m);
  for (int i = 0; i < m; ++i) {
    cin >> coins[i];
  }
  Solution s;
  cout << s.coinChange(coins, n) << endl;
  return 0;
}