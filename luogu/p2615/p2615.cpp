#include <chrono>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

const int maxn = 1e5 + 5;
int N;
map<int, pair<int, int>> M;

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  cin >> N;
  M[1] = make_pair(1, (N + 1) / 2);
  
  vector<vector<int>> cube(N+1, vector<int>(N+1, 0));
  cube[1][(N+1)/2] = 1;
  for(int k=2; k<=N*N; ++k) {
    if (M[k-1].first == 1 && M[k-1].second != N) {
      M[k] = make_pair(N, M[k-1].second + 1);
      cube[N][M[k-1].second+1] = k;
    } else if (M[k-1].second == N && M[k-1].first != 1) {
      M[k] = make_pair(M[k-1].first - 1, 1);
      cube[M[k-1].first-1][1] = k;
    } else if (M[k-1].first == 1 && M[k-1].second == N) {
      M[k] = make_pair(2, N);
      cube[2][N] = k;
    } else {
      if (cube[M[k-1].first - 1][M[k-1].second + 1] == 0) {
        M[k] = make_pair(M[k-1].first - 1, M[k-1].second + 1);
        cube[M[k-1].first-1][M[k-1].second+1] = k;
      } else {
        M[k] = make_pair(M[k-1].first + 1, M[k-1].second);
        cube[M[k-1].first+1][M[k-1].second] = k;
      }
    }
  }
  
  for(int i=1; i<=N; ++i) {
    for(int j=1; j<=N; ++j) {
      cout << cube[i][j] << " ";
    }
    cout << "\n";
  }
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}