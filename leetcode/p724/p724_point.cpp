#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int sum = 0;
    for(int i=0; i<nums.size(); ++i) {
        sum += nums[i];
    }

    int left_sum = 0;
    int right_sum = sum - left_sum;
    if(left_sum == right_sum - nums[0]) return 0;

    for(int i=1; i<nums.size(); ++i) {
      left_sum += nums[i-1];
      right_sum -= nums[i-1];
      if (left_sum == right_sum - nums[i]) return i;
    }
    return -1;
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
  for(int i=0; i<v.size(); ++i) cin >> v[i];
  cout << Solution{}.pivotIndex(v) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}