#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      if (n == 0) return;
      if (m == 0) {
        nums1.swap(nums2); 
        return ;
      }
      int pos1 = m - 1, pos2 = n - 1;
      for(int i=m+n-1; i>=0; --i) {
        if (pos1 < 0 || pos2 < 0) break;

        if (nums1[pos1] >= nums2[pos2]) {
          nums1[i] = nums1[pos1];
          pos1--;
        } else {
          nums1[i] = nums2[pos2];
          pos2--;
        }
      }
      while(pos2 >= 0) {
        nums1[pos2] = nums2[pos2];
        pos2--;
      }
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int m, n;
  cin >> m >> n;
  vector<int> v1(m+n), v2(n);
  for(int i=0; i<m; ++i) cin >> v1[i];
  for(int i=0; i<n; ++i) cin >> v2[i];

  Solution{}.merge(v1, m, v2, n);
  for(auto e : v1) {
    cout << e << " ";
  }
  cout << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}