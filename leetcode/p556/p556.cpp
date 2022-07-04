#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

class Solution {
public:
    int nextGreaterElement(int n) {
      vector<ll> all;
      vector<int> bit;

      int tmp = n;
      while(tmp) {
        bit.push_back(tmp % 10);
        tmp /= 10;
      }
      all = dfs(bit, 0, bit.size()-1);
      sort(all.begin(), all.end());
      auto iter = unique(all.begin(), all.end());
      for(auto it = all.begin(); it != iter; ++it) {
        if (*it == n) {
          if (it + 1 == iter) return -1;
          else return (*(it+1) > 2147483647) ? -1 : *(it+1);
        }
      }
      return -1;
    }

    vector<ll> dfs(const vector<int>& bit, int begin, int end) {
      if (begin == end) return vector<ll>{bit[begin]};

      vector<ll> ans;
      for(int i=begin; i<end; ++i) {
        auto ans1 = dfs(bit, begin, i);
        auto ans2 = dfs(bit, i+1, end);
        for(auto e1 : ans1) {
          if (e1 < pow(10, i-begin)) continue;
          for(auto e2 : ans2) {
              ans.push_back(e1 * pow(10, end-i) + e2);
          }
        }
        for(auto e2 : ans2) {
          if (e2 < pow(10, end-i-1)) continue;
          for(auto e1 : ans1) {
            ans.push_back(e2 * pow(10, i-begin+1) + e1);
          }
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
  cout << Solution{}.nextGreaterElement(n);
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}