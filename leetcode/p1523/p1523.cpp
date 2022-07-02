#include <chrono>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    int countOdds(int low, int high) {
      int ans = (high - low) / 2;
      if (low % 2 == 1 || high % 2 == 1) ans++;
      return ans; 
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int low, high;
  cin >> low >> high;
  cout << Solution{}.countOdds(low, high) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}