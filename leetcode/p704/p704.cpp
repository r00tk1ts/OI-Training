#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    if (nums.empty()) return -1;
    if (nums.size() == 1) return target == nums[0] ? 0 : -1;

    int left = 0, right = nums.size()-1;
    while(left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if(nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return nums[left] == target ? left : -1;
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
  for(int i=0; i<v.size(); ++i) cin >> v[i];

  cout << Solution{}.search(v, t) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}