#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> st;
    for (int i = 0; i < nums.size(); ++i) {
      if (st.find(target - nums[i]) != st.end()) {
        return vector<int>{st[target - nums[i]], i};
      } else {
        st[nums[i]] = i;
      }
    }
    return vector<int>{};
  }
};

int main() {
  vector<int> v{2, 7, 11, 15};
  auto r = Solution().twoSum(v, 9);
  for (auto e : r) {
    cout << e << "\t";
  }
  cout << endl;
  return 0;
}