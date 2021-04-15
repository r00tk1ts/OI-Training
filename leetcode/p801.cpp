#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSwap(vector<int>& A, vector<int>& B) {
    vector<int> dp(A.size() + 1);
    for (int pos = 1; pos < A.size(); ++pos) {
      if (A[pos] > A[pos - 1] && B[pos] > B[pos - 1]) {
        dp[0]++;
      } else {
        break;
      }
    }
    helper(A, B, 0, dp[0], dp);
    for (int i = 0; i < dp.size(); ++i) {
      if (dp[i] == A.size() - 1) return i;
    }
    return -1;
  }
  bool helper(vector<int>& A, vector<int>& B, int cnt, int idx, vector<int>& dp) {
    if (cnt > A.size() / 2) return false;
    if (idx == A.size() - 1) {
      dp[cnt] = idx;
      return true;
    }
    int pos = idx + 1;
    for (; pos < A.size(); ++pos) {
      if (A[pos] <= A[pos - 1] || B[pos] <= B[pos - 1]) {
        break;
      }
    }
    idx = pos - 1;
    dp[cnt] = max(dp[cnt], idx);
    if (idx == A.size() - 1) {
      return true;
    }
    bool flag = false;
    if (idx >= 1) {
      swap(A[idx - 1], B[idx - 1]);
      flag |= helper(A, B, cnt + 1, idx + 1, dp);
      swap(A[idx - 1], B[idx - 1]);
    }
    swap(A[idx], B[idx]);
    flag |= helper(A, B, cnt + 1, idx + 1, dp);
    swap(A[idx], B[idx]);

    return flag;
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