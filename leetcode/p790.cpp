#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // see details in
  // https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116581/Detail-and-explanation-of-O(n)-solution-why-dpn2*dn-1%2Bdpn-3
  // dp[n]=dp[n-1]+dp[n-2]+ 2*(dp[n-3]+...+d[0])
  //      =dp[n-1]+dp[n-2]+dp[n-3]+dp[n-3]+2*(dp[n-4]+...+d[0])
  //      =dp[n-1]+dp[n-3]+(dp[n-2]+dp[n-3]+2*(dp[n-4]+...+d[0]))
  //      =dp[n-1]+dp[n-3]+dp[n-1]
  //      =2*dp[n-1]+dp[n-3]
  // dp[i]只和dp[i-1]和dp[i-3]有关，可以状态压缩成2个变量
  int numTilings(int N) {
    if (N == 0) return 0;
    int mod = 1e9 + 7;
    vector<long> v(N >= 3 ? N + 1 : 4, 0);
    v[1] = 1, v[2] = 2, v[3] = 5;
    for (int i = 4; i <= N; ++i) {
      v[i] = 2 * v[i - 1] + v[i - 3];
      v[i] %= mod;
    }
    return v[N];
  }
};

int main() {
  int n;
  cin >> n;
  Solution s;
  cout << s.numTilings(n) << endl;
  return 0;
}