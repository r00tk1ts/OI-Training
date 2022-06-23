#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxn = 1e5 + 5;

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<int>> v(n+1,vector<int>(k+1, 0));
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      int day;
      cin >> day;
      v[i][day] = j;
    }
  }

  for(int i=1; i<=k; ++i) {
    set<int> s{0};
    for(int j=1; j<=n; ++j) {
      s.insert(v[j][i]);
    }
    cout << s.size() - 1 << " ";
  }
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}