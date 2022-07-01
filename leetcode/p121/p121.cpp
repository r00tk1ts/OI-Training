#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      stack<int> stk;
      int ans = 0;
      stk.push(prices[0]);
      int bottom = prices[0];

      for(int i=1; i<prices.size(); ++i) {
        while(!stk.empty() && stk.top() > prices[i]) {
          ans = max(ans, stk.top() - bottom);
          stk.pop();
        }
        if (stk.empty()) {
          bottom = prices[i];
        }
        stk.push(prices[i]);
      }
    
      return max(ans, stk.top() - bottom);
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
  cout << Solution{}.maxProfit(v);
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}