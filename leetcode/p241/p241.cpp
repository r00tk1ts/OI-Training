#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
      vector<int> ans;
      for(int i=0; i<expression.size(); ++i) {
        char c = expression[i];
        if(c == '+' || c == '-' || c == '*') {
          auto res1 = diffWaysToCompute(expression.substr(0, i));
          auto res2 = diffWaysToCompute(expression.substr(i+1));
          for(auto r1 : res1) {
            for (auto r2 : res2) {
              if (c == '+') ans.push_back(r1 + r2);
              if (c == '-') ans.push_back(r1 - r2);
              if (c == '*') ans.push_back(r1 * r2);
            }
          }
        }
      }
      if (ans.empty()) {
        ans.push_back(stoi(expression));
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

  string expr;
  cin >> expr;
  auto ans = Solution{}.diffWaysToCompute(expr);
  for(auto e : ans) cout << e << " ";
  cout << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}