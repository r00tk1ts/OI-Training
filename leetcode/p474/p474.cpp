#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto& str : strs) {
      int zero_num = 0, one_num = 0;
      for (auto& c : str) {
        if (c == '0')
          zero_num++;
        else if (c == '1')
          one_num++;
      }

      for (int i = m; i >= zero_num; i--) {
        for (int j = n; j >= one_num; j--) {
          dp[i][j] = max(dp[i - zero_num][j - one_num] + 1, dp[i][j]);
        }
      }
    }
    return dp[m][n];
  }
};

int main() {
  vector<string> strs = {"10", "0001", "111001", "1", "0"};
  int m = 5, n = 3;
  Solution s;
  cout << s.findMaxForm(strs, m, n) << endl;
  return 0;
}