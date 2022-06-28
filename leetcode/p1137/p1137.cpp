#include <chrono>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    int tribonacci(int n) {
      int a = 0, b = 1, c = 1;
      if (n == 0) return 0;
      if (n == 1 || n == 2) return 1;

      for(int i=3; i<=n; ++i) {
        int temp = c;
        c = a + b + c;
        a = b;
        b = temp;
      }     
      return c;  
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
  cout << Solution{}.tribonacci(n) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}