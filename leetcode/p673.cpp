#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    // example: 1 3 5 4 7
    // dp[i]表示以i结尾的LIS和累计path数
    vector<Data> dp(nums.size(), {1, 1});
    int max_len = 1;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (dp[i].len < dp[j].len + 1) {
            dp[i].len = dp[j].len + 1;
            dp[i].count = dp[j].count;
          } else if (dp[i].len == dp[j].len + 1) {
            dp[i].count += dp[j].count;
          }
        }
      }
      max_len = max(max_len, dp[i].len);
    }

    int sum = 0;
    for (auto& d : dp) {
      // cout << d.len << "\t" << d.count << endl;
      if (d.len == max_len) {
        sum += d.count;
      }
    }

    return sum;
  }

 private:
  struct Data {
    int len;
    int count;
  };
};

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) cin >> nums[i];
  Solution s;
  cout << s.findNumberOfLIS(nums) << endl;
  return 0;
}