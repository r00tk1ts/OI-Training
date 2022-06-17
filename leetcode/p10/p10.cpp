#include <chrono>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
 public:
  bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();

    if ('*' == p[1])
      return (isMatch(s, p.substr(2)) ||
              !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
    else
      return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
  }
};

class Solution2 {
 public:
  bool isMatch(string s, string p) {
    bool memo[25][35] = {false};
    return dp(s, p, 0, 0, memo);
  }

  bool dp(const string& s, const string& p, int i, int j, bool memo[][35]) {
    if (j == p.length()) {
      memo[i][j] = i == s.length();
      return memo[i][j];
    }

    auto first_match = i < s.length() && (s[i] == p[j] || p[j] == '.');
    if (j + 1 < p.length() && p[j + 1] == '*') {
      memo[i][j] = first_match && dp(s, p, i + 1, j, memo) || dp(s, p, i, j + 2, memo);
    } else {
      memo[i][j] = first_match && dp(s, p, i + 1, j + 1, memo);
    }
    return memo[i][j];
  }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif

  Solution2 sol;
  string s, p;
  cin >> s >> p;
  cout << std::boolalpha << sol.isMatch(s, p);

#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}