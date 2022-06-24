#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long ;

const int maxn = 1e5 + 5;
int n;
ll ans = 0;

vector<int> merge_sort(const vector<int> &v, int begin, int end) {
  if (begin == end) return vector<int>{v[begin]};

  int mid = begin + (end - begin) / 2;
  auto l = merge_sort(v, begin, mid);
  auto r = merge_sort(v, mid + 1, end);
  
  int left = 0, right = 0;
  vector<int> res;
  // 2 4 5
  // 1 3 6
  while(left < l.size() && right < r.size()) {
    if (l[left] > r[right]) {
      ans += (l.size() - left);
      res.push_back(r[right++]);
    } else {
      res.push_back(l[left++]);
    }
  }
  while(left < l.size()) {
    res.push_back(l[left++]);
  }
  while(right < r.size()) {
    res.push_back(r[right++]);
  }
  return res;
}

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif

  cin >> n;
  vector<int> v(n+1);
  for(int i=1; i<=n; ++i) cin >> v[i];

  // 5 4 2 6 3 1
  merge_sort(v, 1, n);
  cout << ans << endl;

#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}