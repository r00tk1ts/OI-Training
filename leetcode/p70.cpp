#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    int a = 1, b = 1;
    for (int i = 2; i <= n; ++i) {
      int temp = a + b;
      a = b;
      b = temp;
    }
    return b;
  }
};

int main() {
  int n;
  cin >> n;
  Solution s;
  cout << s.climbStairs(n) << endl;
  return 0;
}