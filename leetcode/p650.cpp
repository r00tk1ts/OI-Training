#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSteps(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
      dp[i] = i;
      for (int j = i - 1; j > 1; --j) {
        if (i % j == 0) {
          dp[i] = dp[j] + (i / j);
          break;
        }
      }
    }

    return dp[n];
  }
};

int main() {
  int n;
  cin >> n;
  Solution s;
  cout << s.minSteps(n) << endl;
  return 0;
}