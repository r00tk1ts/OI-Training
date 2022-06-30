#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      vector<bool> bitmap(5e5+10);  
      for(int i=0; i<nums.size(); ++i) {
        if (nums[i] > 0 && nums[i] < bitmap.size()) {
          bitmap[nums[i]] = true;
        }
      }
      for(int i=1; i<bitmap.size(); ++i) {
        if(bitmap[i] == false) {
          return i;
        }
      }
      return 1 << 31;
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

  cout << Solution{}.firstMissingPositive(v) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}