#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while(left < right) {
      if(numbers[left] + numbers[right] == target) {
        return vector<int>{left+1, right+1};
      } else if(numbers[left] + numbers[right] > target) {
        right--;
      } else {
        left++;
      }
    } 
    return vector<int>{};   
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
  for(int i=0;i<v.size();++i) cin >> v[i];
  auto ans = Solution{}.twoSum(v, t);
  cout << ans[0] << " " << ans[1] << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}