#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
  int longestValidParentheses(string s) {
    // dp[i]为以s[i]结尾的最长有效子串
    // )()())
    // ()(()))
    int ans = 0;
    vector<int> dp(s.size(), 0);
    for(int i=1; i<dp.size(); ++i) {
      if(s[i] == ')') {
        if (s[i-1] == '(') {
          dp[i] = (i-2>=0 ? dp[i-2] : 0) + 2;
        } else {
          int left = i - dp[i-1] - 1;
          if (left >= 0 && s[left] == '(') {
            dp[i] = dp[i-1] + 2 + (left-1>=0 ? dp[left-1] : 0);
          }
        }
        ans = max(ans, dp[i]);
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
  string str;
  cin >> str;
  cout << Solution{}.longestValidParentheses(str) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}