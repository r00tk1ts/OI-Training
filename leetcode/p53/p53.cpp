#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int max = nums[0];
    int sum = 0;
    for(int i=0; i<nums.size(); ++i) {
      sum += nums[i];
      if (sum > max) max = sum;
      if (sum < 0) sum = 0;
    }
    return max;
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
  cout << Solution{}.maxSubArray(v) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}