#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] == target) {
            return mid;
          } else if (nums[mid] < target) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
        return left;
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for(int i=0; i<n; ++i) cin >> v[i];
  cout << Solution{}.searchInsert(v, t) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}