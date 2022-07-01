#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    void reverseString(vector<char>& s) {
      int left = 0, right = s.size() - 1;
      while(left < right) {
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
      }
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int n;
  cin >> n;
  vector<char> v(n);
  for(int i=0; i<n; ++i) cin >> v[i];
  Solution{}.reverseString(v);
  for(int i=0; i<n; ++i) cout << v[i];
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}