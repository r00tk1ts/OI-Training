#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
      vector<vector<int>> ans;
      sort(arr.begin(), arr.end());
      int min_diff = arr[1] - arr[0];
      for(int i=1; i<arr.size()-1; ++i) min_diff = min(min_diff, arr[i+1] - arr[i]);

      for(int i=0; i<arr.size()-1; ++i) {
        if (arr[i+1] - arr[i] == min_diff) {
          ans.push_back(vector<int>{arr[i], arr[i+1]});
        }
      }
      return ans;
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
  auto ans = Solution{}.minimumAbsDifference(v);
  for(auto i=0; i<ans.size(); ++i) {
    for(auto e : ans[i]) {
      cout << e << " ";
    }
    cout << "\n";
  }
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}