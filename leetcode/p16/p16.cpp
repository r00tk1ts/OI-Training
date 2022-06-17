#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int idx = 0;
    int res = INT_MAX;
    bool flag = true;
    while (idx < nums.size()) {
      int left = idx + 1, right = nums.size() - 1;
      while (left < right) {
        int diff = nums[left] + nums[right] + nums[idx] - target;
        cout << diff << "\n";
        if (diff == 0) {
          return target;
        } else if (diff > 0) {
          right--;
        } else {
          left++;
        }
        if (abs(diff) < res) {
          res = abs(diff);
          flag = diff > 0;
        }
      }
      idx++;
    }

    if (flag)
      return res + target;
    else
      return target - res;
  }
};

int main() {
  vector<int> nums{-1, 2, 1, -4};
  cout << Solution().threeSumClosest(nums, 1) << endl;
  return 0;
}