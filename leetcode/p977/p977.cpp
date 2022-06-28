#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int number = nums.size();
      vector<int> v(number);
      int left = 0, right = number - 1;
      int pos = number - 1;

      while(left <= right) {
        if (nums[left] * nums[left] >= nums[right] * nums[right]) {
          v[pos--] = nums[left] * nums[left];
          left++;
        } else {
          v[pos--] = nums[right] * nums[right];
          right--;
        }
      }
      return v;
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

  auto ans = Solution{}.sortedSquares(v);
  for(auto elem : ans) cout << elem << " ";
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}