#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      set<int> uni;
      for(auto &num : nums) {
        if (uni.find(num) != uni.end()) return true;
        uni.insert(num);
      }
      return false;
    }

    bool containsDuplicate2(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      for(int i=0; i<nums.size()-1; ++i) {
        if (nums[i] == nums[i+1]) return true;
      }
      return false;
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

  cout << boolalpha << Solution{}.containsDuplicate(v) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}