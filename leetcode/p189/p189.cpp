#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k %= nums.size();
      reverse(nums.begin(), nums.end());
      reverse(nums.begin(), nums.begin()+k);
      reverse(nums.begin()+k, nums.end());
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif

  // 1 2 3 4 5 6 7 => rotate k = 3
  // 7 6 5 4 3 2 1 => rotate all
  // 5 6 7 1 2 3 4 => rotate 1~3, rotate 4~7
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for(int i=0; i<n; ++i) cin >> v[i];
  
  Solution{}.rotate(v, k);
  for(int i=0; i<n; ++i) cout << v[i] << " ";
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}