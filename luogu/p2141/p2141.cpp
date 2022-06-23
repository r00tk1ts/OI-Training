#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int count_two_sum(vector<int>& v) {
  sort(v.begin(), v.end());

  int ans = 0;
  for(int pos = v.size()-1; pos>=2; --pos) {
    int left = 0, right = pos - 1;
    while(left < right) {
      auto sum = v[right] + v[left];
      if (sum == v[pos]) {
        ans++;
        break;
      } else if (sum > v[pos]) {
        right--;
      } else {
        left++;
      }
    }
  }  

  return ans;
}

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; ++i) {
    cin >> v[i];
  }
  cout << count_two_sum(v) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}