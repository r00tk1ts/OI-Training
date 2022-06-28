#include <chrono>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    bool isSubsequence(string s, string t) {
      int first = 0, second = 0;
      while(first < s.size() && second < t.size()) {
        if(s[first] == t[second]) {
          first++;
          second++;
        } else {
          second++;
        }
      }
      return first == s.size() ? true : false;
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  string s, t;
  cin >> s >> t;

  cout << boolalpha << Solution{}.isSubsequence(s, t);
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}