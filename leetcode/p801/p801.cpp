#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSwap(vector<int>& A, vector<int>& B) {
    int n = A.size();
    // 思路:
    // 1维0表示不交换A[i]和B[i]，1表示交换A[i]和B[i]
    // dp[0/1][i]表示交换或不交换A[i]和B[i]时，保证A[0~i]和B[0~i]递增的最少累计交换次数
    // 随着idx的前进，我们只需要处理两种情况（可同时出现）：
    // 1. A[i-1] < A[i] && B[i-1] < B[i]
    // 2. A[i-1] < B[i] && B[i-1] < A[i]
    // case 1:
    // 如果交换A[i]和B[i]，那么A[i-1]和B[i-1]也要交换才能保证递增，此时dp[1][i] = dp[1][i-1] + 1
    // 如果不交换A[i]和b[i]，那么dp[0][i] = dp[0][i-1]
    // case 2:
    // 如果交换A[i]和B[i]，那么A[i-1]和B[i-1]就不能交换才能保证递增，此时dp[1][i] = dp[0][i-1] + 1
    // 如果不交换A[i]和B[i]，那么A[i-1]和B[i-1]就必须交换来保证递增，此时dp[0][i] = dp[1][i-1]
    //
    // case1和case2对dp[0/1][i]的结果取最小值
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = 0, dp[1][0] = 1;
    for (int i = 1; i < n; ++i) {
      dp[0][i] = dp[1][i] = n;
      if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
        dp[1][i] = dp[1][i - 1] + 1;
        dp[0][i] = dp[0][i - 1];
      }
      if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
        dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1);
        dp[0][i] = min(dp[0][i], dp[1][i - 1]);
      }
    }
    return min(dp[0][n - 1], dp[1][n - 1]);
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> B[i];
  }
  Solution s;
  cout << s.minSwap(A, B) << endl;
  return 0;
}