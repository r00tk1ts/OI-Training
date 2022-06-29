#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 0 1 0 3 12
        int left = 0;
        for(int i=0; i<nums.size(); ++i) {
          if (nums[i] != 0) {
            nums[left++] = nums[i];
          }
        }

        while(left < nums.size()) {
          nums[left++] = 0;
        }
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
  Solution{}.moveZeroes(v);
  for(auto e : v) cout << e << " ";
  cout << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}