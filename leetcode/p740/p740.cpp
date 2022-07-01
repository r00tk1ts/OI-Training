#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      vector<int> dp(10005, 0);
      int sum = 0, idx = 0;
      while(idx < nums.size() && nums[idx] == 1) {
        idx++;
        sum++;
      }
      dp[1] = sum;

      for(int i=2; i<=10000; ++i) {
        sum = 0;
        while(idx < nums.size() && nums[idx] == i) {
          idx++;
          sum += i;
        }
        dp[i] = max(dp[i-1], dp[i-2] + sum);
        if (idx == nums.size()) return dp[i];
      }
      return 0;
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
  cout << Solution{}.deleteAndEarn(v) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}