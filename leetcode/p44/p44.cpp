#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    bool isMatch(string s, string p) {
      vector<vector<int>> v(s.size()+1, vector<int>(p.size()+1, -1));
      return isMatchHelper(s, 0, p, 0, v);  
    }

    bool isMatchHelper(const string &s, int s_pos, const string& p, int p_pos, vector<vector<int>>& v) {
      if (v[s_pos][p_pos] >= 0) {
        return v[s_pos][p_pos] == 1 ? true : false;
      }

      if (p_pos == p.size()) {
        v[s_pos][p_pos] = s_pos == s.size() ? 1 : 0;
        return v[s_pos][p_pos];
      }

      if (s_pos == s.size()) {
        v[s_pos][p_pos] = (p[p_pos] == '*' && isMatchHelper(s, s_pos, p, p_pos+1, v));
        return v[s_pos][p_pos];
      }

      bool match = s_pos < s.size() && (p[p_pos] == '?' || p[p_pos] == s[s_pos]);
      if (p[p_pos] == '*') {
        v[s_pos][p_pos] = static_cast<int>(isMatchHelper(s, s_pos+1, p, p_pos, v) 
          || isMatchHelper(s, s_pos, p, p_pos+1, v));
      } else {
        v[s_pos][p_pos] = static_cast<int>(match && isMatchHelper(s, s_pos+1, p, p_pos+1, v));
      }
      return v[s_pos][p_pos];
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  string s,p;
  cin >> s >> p;
  cout << boolalpha << Solution{}.isMatch(s, p) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}