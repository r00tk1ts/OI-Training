#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      if(nums1.size() > nums2.size()) nums1.swap(nums2);  

      map<int, int> mp;
      vector<int> ans;
      
      for(auto e1 : nums1) {
        mp[e1]++;
      }

      for(auto e2 : nums2) {
        auto iter = mp.find(e2);
        if (iter == mp.end() || iter->second == 0) continue;
        ans.push_back(iter->first);
        iter->second--;
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
  int n, m;
  cin >> n >> m;
  vector<int> nums1(n), nums2(m);
  for(int i=0; i<n; ++i) cin >> nums1[i];
  for(int i=0; i<m; ++i) cin >> nums2[i];
  auto ans = Solution{}.intersect(nums1, nums2);
  for(auto e : ans) cout << e << " ";
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}