#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(366, INT_MAX);
    dp[0] = 0;
    int idx = 0;
    for (int i = 1; i <= 365; ++i) {
      while (days[idx] < i) {
        if (idx + 1 < days.size())
          idx++;
        else
          break;
      }
      if (days[idx] != i) {
        dp[i] = dp[i - 1];
        continue;
      }

      dp[i] = min(dp[i], dp[i - 1] + costs[0]);
      for (int j = 1; j <= 7; ++j) {
        if (i - j >= 0) {
          dp[i] = min(dp[i], dp[i - j] + costs[1]);
        }
      }
      for (int j = 1; j <= 30; ++j) {
        if (i - j >= 0) {
          dp[i] = min(dp[i], dp[i - j] + costs[2]);
        }
      }
    }
    return dp[365];
  }
};

int main() {
  int n;
  vector<int> costs(3);
  cin >> n >> costs[0] >> costs[1] >> costs[2];

  vector<int> days(n);
  for (int i = 0; i < n; ++i) cin >> days[i];

  Solution s;
  cout << s.mincostTickets(days, costs) << endl;
  return 0;
}