#include <bits/stdc++.h>

using namespace std;

// dfs解法，会超时
/*
class Solution {
 public:
  int findPaths(int m, int n, int N, int i, int j) {
    int methods = 0;
    helper(m, n, N, i + 1, j + 1, methods);
    return methods;
  }

  void helper(int m, int n, int N, int i, int j, int& methods) {
    if (N < 0) return;
    if (i < 0 || i > m + 1 || j < 0 || j > n + 1) return;
    if (i == 0 || i == m + 1 || j == 0 || j == n + 1) {
      methods = (methods + 1) % 1000000007;
      return;
    }
    helper(m, n, N - 1, i - 1, j, methods);
    helper(m, n, N - 1, i + 1, j, methods);
    helper(m, n, N - 1, i, j - 1, methods);
    helper(m, n, N - 1, i, j + 1, methods);
  }
};
*/

// dfs返回void形式的dp+memo，这种方法需要提前填充初值
class MemoVoidSolution {
 public:
  int findPaths(int m, int n, int N, int i, int j) {
    // 数据保护
    if (N == 0) return 0;
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
    for (int i = 0; i < m; ++i) {
      dp[1][i][0]++;
      dp[1][i][n - 1]++;
    }
    for (int j = 0; j < n; ++j) {
      dp[1][0][j]++;
      dp[1][m - 1][j]++;
    }
    for (int t = 1; t <= N; ++t) {
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dp[t][i][j] == 0) dp[t][i][j] = -1;
        }
      }
    }

    dfs(m, n, N, i, j, dp);
    return dp[N][i][j];
  }

  void dfs(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& dp) {
    if (N == 0) {
      return;
    }
    if (dp[N][i][j] != -1) return;
    dp[N][i][j] = 0;
    if (i - 1 >= 0) {
      dfs(m, n, N - 1, i - 1, j, dp);
      dp[N][i][j] = (dp[N][i][j] + dp[N - 1][i - 1][j]) % mod;
    } else {
      dp[N][i][j] += 1;
    }

    if (i + 1 < m) {
      dfs(m, n, N - 1, i + 1, j, dp);
      dp[N][i][j] = (dp[N][i][j] + dp[N - 1][i + 1][j]) % mod;
    } else {
      dp[N][i][j] += 1;
    }

    if (j - 1 >= 0) {
      dfs(m, n, N - 1, i, j - 1, dp);
      dp[N][i][j] = (dp[N][i][j] + dp[N - 1][i][j - 1]) % mod;
    } else {
      dp[N][i][j] += 1;
    }

    if (j + 1 < n) {
      dfs(m, n, N - 1, i, j + 1, dp);
      dp[N][i][j] = (dp[N][i][j] + dp[N - 1][i][j + 1]) % mod;
    } else {
      dp[N][i][j] += 1;
    }
  }

 private:
  static constexpr int mod = 1000000000 + 7;
};

// dfs改一改就是自顶向下型dp+memo
class MemoSolution {
 public:
  int findPaths(int m, int n, int N, int i, int j) {
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, -1)));
    return dfs(m, n, N, i, j, dp);
  }

  int dfs(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& dp) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return 1;
    }
    if (dp[N][i][j] != -1) return dp[N][i][j];
    if (N == 0) {
      return 0;
    }
    dp[N][i][j] = 0;
    dp[N][i][j] = (dp[N][i][j] + dfs(m, n, N - 1, i - 1, j, dp) % mod) % mod;
    dp[N][i][j] = (dp[N][i][j] + dfs(m, n, N - 1, i + 1, j, dp) % mod) % mod;
    dp[N][i][j] = (dp[N][i][j] + dfs(m, n, N - 1, i, j - 1, dp) % mod) % mod;
    dp[N][i][j] = (dp[N][i][j] + dfs(m, n, N - 1, i, j + 1, dp) % mod) % mod;
    return dp[N][i][j];
  }

 private:
  static constexpr int mod = 1000000000 + 7;
};

class Solution {
 public:
  int findPaths(int m, int n, int N, int i, int j) {
    // 我们将m和n围成的坐标系扩大一圈，最外圈除4个顶点外的所有点都是临界点，也就是可行的最终出口坐标。
    // 从(i,j)到任意边界的路径数和从任意边界到(i,j)的路径数是一样的（互逆）。
    // 定义三维dp，dp[N][x][y]表示从任意边界到(x,y)至多用N步的路径数，
    // 而(x,y)只会从上下左右四个临近坐标到达，从而得到状态转移方程：
    // dp[N][x][y] = dp[N-1][x-1][y] + dp[N-1][x+1][y] + dp[N-1][x][y-1] + dp[N-1][x][y+1]
    // 还要考虑临近坐标是临界点的情况，如果某个临近坐标本身是临界点，那么跳到(x,y)的路径就只有1个，不论N有多大
    // 因为我们不能在最外圈反复横跳，最外圈是虚拟的
    vector<vector<vector<uint32_t>>> dp(51, vector<vector<uint32_t>>(50, vector<uint32_t>(50)));
    for (int t = 1; t <= N; ++t) {
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          dp[t][i][j] =
              ((i == 0 ? 1 : dp[t - 1][i - 1][j]) + (i == m - 1 ? 1 : dp[t - 1][i + 1][j]) +
               (j == 0 ? 1 : dp[t - 1][i][j - 1]) + (j == n - 1 ? 1 : dp[t - 1][i][j + 1])) %
              1000000007;
        }
      }
    }
    return dp[N][i][j];
  }
};

int main() {
  int m, n, N, i, j;
  cin >> m >> n >> N >> i >> j;
  MemoVoidSolution s;
  cout << s.findPaths(m, n, N, i, j) << endl;
  return 0;
}