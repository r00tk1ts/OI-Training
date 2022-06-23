#include <chrono>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

int calc(int n, int k, int cur) {
  if (k == 1) {
    if (n >= cur) 
      return 1;
    else 
      return 0;
  } 

  int ans = 0;
  for(int i=cur; i<=n/k; ++i) {
    ans += calc(n-i, k-1, i);
  }
  return ans;
}


int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif

  int n, k;
  cin >> n >> k;

  int ans = 0;
  ans = calc(n, k, 1);
  cout << ans << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}