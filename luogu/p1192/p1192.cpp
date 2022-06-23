#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 3;

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif

  int n, k;
  cin >> n >> k;

  vector<int> dp(n+1);
  dp[0] = 1;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=min(i,k); ++j) {
      dp[i] = (dp[i] + dp[i-j]) % maxn;
    }
  }
  cout << dp[n] << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}