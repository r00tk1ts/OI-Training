#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int idx = 0;
    while (idx < nums.size()) {
      int left = idx + 1, right = nums.size() - 1;
      while (left < right) {
        if (nums[left] + nums[right] + nums[idx] < 0) {
          left++;
        } else if (nums[left] + nums[right] + nums[idx] > 0) {
          right--;
        } else {
          res.push_back({nums[idx], nums[left], nums[right]});
          left++;
          right--;
          while (left < nums.size() && nums[left] == nums[left - 1]) left++;
          while (right > 0 && nums[right] == nums[right + 1]) right--;
        }
      }
      do {
        idx++;
      } while (idx < nums.size() && nums[idx] == nums[idx - 1]);
    }
    return res;
  }
};
//- 4 - 1 - 1 0 1 2
int main() {
  vector<int> nums{-1, 0, 1, 2, -1, -4};
  auto res = Solution().threeSum(nums);
  for (auto r : res) {
    for (auto e : r) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}