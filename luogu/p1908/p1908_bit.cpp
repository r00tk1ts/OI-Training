#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
using ll = long long ;

struct point {
  int sequence;
  int value;
};

const int maxn = 5e5 + 5;
int n, tree[maxn], ranks[maxn];
ll ans = 0;
point a[maxn];

bool cmp(point a, point b) {
  if (a.value == b.value) return a.sequence < b.sequence;
  return a.value < b.value;
}

void insert(int p, int d) {
  for(; p<=n; p+=p&-p) {
    tree[p] += d;
  }
}

int query(int p) {
  int sum = 0;
  for(; p; p-=p&-p) {
    sum += tree[p];
  }
  return sum;
}

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif

  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i].value;
    a[i].sequence = i;
  }

  // 按值排序
  // value:     5 4 2 6 3 1
  // sequence:  1 2 3 4 5 6
  sort(a+1, a+1+n, cmp);
  // value:     1 2 3 4 5 6
  // sequence:  6 3 5 2 1 4
  
  // 离散化，保证ranks值的有限性与连续性
  for(int i=1; i<=n; ++i) {
    ranks[a[i].sequence] = i;
  }
  // ranks: 5 4 2 6 3 1
  // 用rank值建树状数组，从左到右值+1更新，表示又有一个数出现
  // 循环到第i项时，前i-1项已经都在数组中了，数组中rank值比ai大的，都会形成逆序对
  // 而我们可以通过query(ai)拿到[1,ai]区间和，也就是前1~i项的所有数<=ai的个数，
  // 那么i-query(ai)就是大于ai rank值的所有数
  for(int i=1; i<=n; ++i) {
    insert(ranks[i], 1);
    ans += i - query(ranks[i]);
  }
  cout << ans << endl;

#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}