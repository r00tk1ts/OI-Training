#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    int rob(vector<int>& nums) {
      if (nums.size() <= 1) return nums[0];
      
      vector<vector<int>> dp(nums.size(), vector<int>(2));
      dp[0][1] = nums[0], dp[1][1] = nums[1];
      dp[0][0] = 0, dp[1][0] = nums[0];

      for(int i=2; i<nums.size(); ++i) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0], dp[i-2][1]) + nums[i];
      }
      return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
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

  cout << Solution{}.rob(v);
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}