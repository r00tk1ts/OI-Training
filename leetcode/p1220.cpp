#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int countVowelPermutation(int n) {
    const int mod = 1e9 + 7;
    map<char, int> mp{{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    vector<vector<int>> dp(5, vector<int>(n + 1, 0));
    dp[mp['a']][1] = dp[mp['e']][1] = dp[mp['i']][1] = dp[mp['o']][1] = dp[mp['u']][1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[mp['a']][i] = (dp[mp['a']][i] + dp[mp['e']][i - 1]) % mod;
      dp[mp['a']][i] = (dp[mp['a']][i] + dp[mp['i']][i - 1]) % mod;
      dp[mp['a']][i] = (dp[mp['a']][i] + dp[mp['u']][i - 1]) % mod;

      dp[mp['e']][i] = (dp[mp['e']][i] + dp[mp['a']][i - 1]) % mod;
      dp[mp['e']][i] = (dp[mp['e']][i] + dp[mp['i']][i - 1]) % mod;

      dp[mp['i']][i] = (dp[mp['i']][i] + dp[mp['e']][i - 1]) % mod;
      dp[mp['i']][i] = (dp[mp['i']][i] + dp[mp['o']][i - 1]) % mod;

      dp[mp['o']][i] = (dp[mp['o']][i] + dp[mp['i']][i - 1]) % mod;

      dp[mp['u']][i] = (dp[mp['u']][i] + dp[mp['i']][i - 1]) % mod;
      dp[mp['u']][i] = (dp[mp['u']][i] + dp[mp['o']][i - 1]) % mod;
    }
    int res = 0;
    for (int i = 0; i < 5; ++i) {
      res = (res + dp[i][n]) % mod;
    }
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  Solution s;
  cout << s.countVowelPermutation(n) << endl;
  return 0;
}