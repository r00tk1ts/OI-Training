#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numTrees(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(1, n, dp);
  }
  int helper(int left, int right, vector<vector<int>>& dp) {
    // 树为空视为nullptr，作为root的左右子树也算一种
    if (left > right) return 1;
    if (left == right) return 1;
    if (dp[left][right] != -1) return dp[left][right];
    dp[left][right] = 0;
    for (int root = left; root <= right; ++root) {
      int totalLeft = helper(left, root - 1, dp);
      int totalRight = helper(root + 1, right, dp);
      // if (totalLeft == 0) totalLeft = 1;
      // if (totalRight == 0) totalRight = 1;
      dp[left][right] += totalLeft * totalRight;
    }
    return dp[left][right];
  }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().numTrees(n) << endl;
  return 0;
}