#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

bool judge(const vector<int> &v, int distance, int count) {
  int cnt = 0;
  int i = 0;
  int cur = 0;
  while(i < v.size() - 1) {
    i++;
    if (v[i] - v[cur] < distance) {
      cnt++;
    } else {
      cur = i;
    }
  }
  if (cnt > count) 
    return false;
  else 
    return true;
}

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int l, n, m;
  cin >> l >> n >> m;
  // 0 2 11 14 17 21 25, n=5
  vector<int> v(n+2);
  for(int i=1; i<=n; ++i) {
    cin >> v[i];
  }
  v[n+1] = l;

  int left = 1, right = l;
  int ans;
  while(left <= right) {
    auto mid = left + (right - left) / 2;
    if (judge(v, mid, m)) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << ans << endl;
 
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}