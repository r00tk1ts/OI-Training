#include <chrono>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;
int n, bad;

bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int left = 1, right = n;
    while(left <= right) {
      int mid = left + (right - left) / 2;
      if (isBadVersion(mid) == true) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;      
  }
};

bool isBadVersion(int version) {
  return version >= bad ? true : false;
}

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  cin >> n >> bad;
  cout << Solution{}.firstBadVersion(n) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}