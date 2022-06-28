#include <chrono>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    int fib(int n) {
      int a = 0, b = 1;
      if (n == 0) return a;
      if (n == 1) return b;
      for(int i=2; i<=n; ++i) {
        int temp = a;
        a = b;
        b += temp;
      }
      return b;
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
  cout << Solution{}.fib(n) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}