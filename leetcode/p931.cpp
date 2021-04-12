#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int col = 0; col < n; ++col) {
      dp[0][col] = matrix[0][col];
    }
    for (int row = 1; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        int temp = INT_MAX;
        if (col - 1 >= 0) {
          temp = min(temp, dp[row - 1][col - 1]);
        }
        if (col + 1 < n) {
          temp = min(temp, dp[row - 1][col + 1]);
        }
        temp = min(temp, dp[row - 1][col]);
        dp[row][col] = temp + matrix[row][col];
      }
    }

    int path = dp[n - 1][0];
    for (int col = 1; col < n; ++col) {
      path = min(path, dp[n - 1][col]);
    }
    return path;
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }
  Solution s;
  cout << s.minFallingPathSum(matrix) << endl;
  return 0;
}