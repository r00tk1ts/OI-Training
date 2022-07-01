#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    int rob(vector<int>& nums) {
      if (nums.size() == 0) return 0;
      if (nums.size() == 1) return nums[0];
      if (nums.size() == 2) return max(nums[0], nums[1]);

      vector<int> v1(nums.begin(), nums.end() - 1);
      vector<int> v2(nums.begin() + 1, nums.end());
      return max(rob_helper(v1), rob_helper(v2));
    }

    int rob_helper(vector<int>& nums) {
      int dp[nums.size()];
      dp[0] = nums[0];
      dp[1] = max(nums[0], nums[1]);
      for(int i=2; i<nums.size(); ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
      }
      return dp[nums.size()-1];
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; ++i) cin >> v[i];
  cout << Solution{}.rob(v) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}