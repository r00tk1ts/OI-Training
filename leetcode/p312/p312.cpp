#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    // 用两个dummy气球做补位，这两个气球不会被引爆
    vector<int> arr = {1};
    for (auto x : nums) arr.push_back(x);
    arr.push_back(1);
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));
    // 区间从1到n-2，首尾两个dummy气球不能被引爆
    return helper(1, arr.size() - 2, arr, dp);
  }

  int helper(int left, int right, vector<int>& nums, vector<vector<int>>& dp) {
    if (left > right) return 0;
    if (left == right) {
      return nums[left - 1] * nums[left] * nums[left + 1];
    }
    if (dp[left][right] != -1) return dp[left][right];
    int ans = 0;
    // 在left到right区间内选择被最后一个引爆的气球k
    // k气球左侧和右侧引爆的值可以独立计算并累加
    // k气球本身被引爆时，看到的是[left,right]界外的首个气球，即left-1,right+1
    for (int k = left; k <= right; ++k) {
      ans = max(ans,
                nums[left - 1] * nums[k] * nums[right + 1] + helper(left, k - 1, nums, dp) +
                    helper(k + 1, right, nums, dp));
    }
    return dp[left][right] = ans;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) cin >> nums[i];
  cout << Solution().maxCoins(nums) << endl;
  return 0;
}