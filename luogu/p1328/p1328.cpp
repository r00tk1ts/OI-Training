#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

// 0: 剪刀，1：石头，2：布，3：蜥蜴人，4：斯波克
// 一维对二维的得分
int relation[5][5] = {
  {0,0,1,1,0},
  {1,0,0,1,0},
  {0,1,0,0,1},
  {0,0,1,0,1},
  {1,1,0,0,0},
};

int gcd(int a, int b) {
  while(a != b) {
    if (a > b) {
      a -= b;
    } else { 
      b -= a;
    }
  }
  return a;
}

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int n, a, b;
  cin >> n >> a >> b;
  int p = a * b / gcd(a, b);

  vector<int> va(a), vb(b);
  for(int i=0; i<a; ++i) cin >> va[i];
  for(int i=0; i<b; ++i) cin >> vb[i];

  int idx = 0;
  for(int i=a; i<p; ++i) {
    va.push_back(va[idx++]);
  }
  idx = 0;
  for(int i=b; i<p; ++i) {
    vb.push_back(vb[idx++]);
  }

  int sum_a = 0, sum_b = 0;
  for(int i=0; i<p; ++i) {
    sum_a += relation[va[i]][vb[i]];
    sum_b += relation[vb[i]][va[i]];
  }

  sum_a *= n / p;
  sum_b *= n / p;
  for(int i=0; i<n%p; ++i) {
    sum_a += relation[va[i]][vb[i]];
    sum_b += relation[vb[i]][va[i]];
  }
  cout << sum_a << " " << sum_b << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}