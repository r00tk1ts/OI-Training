#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    void reverse(string& s, int left, int right) {
      while(left < right) {
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
      }
    }

    string reverseWords(string s) {
      string ans = std::move(s);
      int left = 0, right;
      for(int i=0; i<ans.size(); ++i) {
        if (ans[i] == ' ') {
          right = i - 1;
          reverse(ans, left, right);
          left = i + 1;
        }
      }
      reverse(ans, left, ans.size()-1);
      return ans;
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  string s;
  getline(cin, s);
  cout << Solution{}.reverseWords(s);
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}