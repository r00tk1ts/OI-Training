#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    vector<bool> dp(sum / 2 + 1, false);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      for (int t = sum >> 1; t >= nums[i]; --t) {
        dp[t] = dp[t] | dp[t - nums[i]];
      }
    }

    return dp[sum / 2];
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  Solution s;
  cout << boolalpha << s.canPartition(nums) << endl;
  return 0;
}