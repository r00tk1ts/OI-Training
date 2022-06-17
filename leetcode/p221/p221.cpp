#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ret = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
      ret = max(dp[i][0], ret);
    }
    for (int j = 0; j < n; ++j) {
      dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
      ret = max(dp[0][j], ret);
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == '1') {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
          ret = max(dp[i][j], ret);
        } else {
          dp[i][j] = 0;
        }
      }
    }
    return ret * ret;
  }
};

int main() {
  int n, m;
  cin >> m >> n;

  vector<vector<char>> matrix(m, vector<char>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int temp;
      cin >> temp;
      matrix[i][j] = (temp == 1 ? '1' : '0');
    }
  }

  Solution s;
  cout << s.maximalSquare(matrix) << endl;
  return 0;
}