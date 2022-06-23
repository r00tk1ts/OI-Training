#include <chrono>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

using ll = long long;
ll fp[10000002] = {0};

int f(ll n, ll m) {
  // 记忆化存储，避免递归导致的重复计算
  if(fp[n]) return fp[n];
  if(n == 1 || n == 2) return fp[n] = 1 % m;
  fp[n] = (f(n-1, m) + f(n-2, m)) % m;
  return fp[n];
}

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int m;
  cin >> m;

  ll i=1;
  while(f(i, m) != 0 || f(i+1, m) != 1){
      i++;
  }
  cout << i << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}