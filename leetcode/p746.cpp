#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size() + 1, 0);
    for (int i = 2; i < dp.size(); ++i) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[dp.size() - 1];
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> cost(n);
  for (int i = 0; i < n; ++i) {
    cin >> cost[i];
  }
  Solution s;
  cout << s.minCostClimbingStairs(cost) << endl;
  return 0;
}