#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  double knightProbability(int N, int K, int r, int c) {
    vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, -1)));
    return dfs(N, K, r, c, dp);
  }

  double dfs(int N, int K, int r, int c, vector<vector<vector<double>>>& dp) {
    if (r < 0 || r >= N || c < 0 || c >= N) {
      return 0;
    }
    if (dp[K][r][c] != -1) {
      return dp[K][r][c];
    }
    if (K == 0) {
      return 1;
    }
    dp[K][r][c] = 0;
    for (auto& offset : s_offset) {
      int x = r + offset.x;
      int y = c + offset.y;
      double ret = dfs(N, K - 1, x, y, dp) * 0.125;
      dp[K][r][c] += ret;
    }
    return dp[K][r][c];
  }

 private:
  struct Offset {
    int x;
    int y;
  };
  static const vector<Offset> s_offset;
};

const vector<Solution::Offset> Solution::s_offset = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main() {
  int N, K, r, c;
  cin >> N >> K >> r >> c;
  Solution s;
  cout << s.knightProbability(N, K, r, c) << endl;
  return 0;
}