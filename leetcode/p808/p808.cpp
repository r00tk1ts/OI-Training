#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  double soupServings(int N) {
    if (N > 4800) return 1;
    if (N % 25 == 0)
      N /= 25;
    else
      N = N / 25 + 1;
    vector<vector<double>> dp(N + 1, vector<double>(N + 1, -1));
    return dfs(N, N, dp);
  }
  double dfs(int A, int B, vector<vector<double>>& dp) {
    if (A <= 0 && B <= 0) return 0.5;
    if (A <= 0) return 1;
    if (B <= 0) return 0;
    if (dp[A][B] != -1) return dp[A][B];
    dp[A][B] = 0;
    for (auto data : s_data) {
      int x = A + data.x;
      int y = B + data.y;
      dp[A][B] += 0.25 * dfs(x, y, dp);
    }
    return dp[A][B];
  }

 public:
  struct Data {
    int x;
    int y;
  };
  static const vector<Data> s_data;
};

const vector<Solution::Data> Solution::s_data = {{-4, 0}, {-3, -1}, {-2, -2}, {-1, -3}};

int main() {
  int N;
  cin >> N;
  Solution s;
  cout << s.soupServings(N) << endl;
  return 0;
}