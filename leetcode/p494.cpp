#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 这个题用这种解法，细节比较多，记录一下
  // 思路就是计算nums凑成1~sum中的每个数各有几种方法
  // x + y = sum
  // x - y = target
  // dp[i]表示凑成i的方法数量，然后我们查找凑成x或y的方法数量
  // 一旦x的某个方法确定了，那么凑成y的方法也就一对一确定了，因此dp[x] == dp[y]
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // 边界条件判定
    if (target < -sum || target > sum) return 0;
    if ((target + sum) % 2) return 0;

    // 我们只需要算正数即可，正数和负数的方法是镜像对称的
    if (target < 0) target = -target;
    vector<int> dp(sum + 1);
    int zero_cnt = 0;
    if (dp[0] == 0) dp[0] = 1;
    for (auto& num : nums) {
      if (num == 0) {
        zero_cnt++;
        continue;
      }
      for (int i = sum; i >= num; --i) {
        dp[i] += dp[i - num];
      }
    }

    int res = (target + sum) / 2;
    // 0可以随意安排给x或y，所以每有1个零，总体数量就倍增
    return dp[res] * pow(2, zero_cnt);
  }
};

int main() {
  int target, n;
  cin >> target >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) cin >> nums[i];
  Solution s;
  cout << s.findTargetSumWays(nums, target) << endl;
  return 0;
}