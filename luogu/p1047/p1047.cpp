#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif

  vector<int> road(1e4+5, 0);
  int l, m;
  cin >> l >> m;
  for(int i=0; i<=l; ++i) {
    road[i] = 1;
  }
  for(int i=0; i<m; ++i) {
    int u, v;
    cin >> u >> v;
    for(int j=u; j<=v; ++j) {
      road[j] = 0;
    }
  }
  cout << count(road.begin(), road.end(), 1) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}