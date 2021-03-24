#include <bits/stdc++.h>

using namespace std;

int n, m, dp[10005] = {1}, v[10005];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = m; j - v[i] >= 0; --j) {
      dp[j] += dp[j - v[i]];
    }
  }
  cout << dp[m] << endl;
  return 0;
}