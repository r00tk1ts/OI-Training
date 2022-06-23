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
    int n, k, f[201][7];
    cin >> n >> k;

    for (int i=1;i<=n;i++) {f[i][1]=1;f[i][0]=1;}
    for (int x=2;x<=k;x++) {f[1][x]=0;f[0][x]=0;}  // 边界，为了防止炸，我把有0的也处理了

    for (int i=2;i<=n;i++)
        for (int x=2;x<=k;x++)
            if (i>x) 
                f[i][x]=f[i-1][x-1]+f[i-x][x];
            else 
                f[i][x]=f[i-1][x-1];

    /*
    for(auto i=1; i<=n; ++i) {
        for(auto j=1; j<=k; ++j) {
            cout << f[i][j] << "\t";
        }
        cout << endl;
    }
    */
    cout << f[n][k];
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}