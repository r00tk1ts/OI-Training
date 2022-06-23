#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>

using namespace std;

const int maxn = 1e5 + 5;

string clean_pattern(const string& pattern) {
  deque<char> stk;
  for(auto &ch : pattern) {
    if (ch == '<' && !stk.empty()) {
      stk.pop_back();
    } else if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '.' || ch == ' '){
      stk.push_back(ch);
    }
   }

   string line;
   while(!stk.empty()) {
    line.push_back(stk.front());
    stk.pop_front();
   }
   return line;
}

int calc_correct_ch(const string& pattern, const string& input) {   
   auto p = clean_pattern(pattern);
   auto l = clean_pattern(input);
   
   int ans = 0;
   for(int i=0; i<min(p.size(), l.size()); ++i) {
    if (l[i] == p[i]) ans++;
   }

   return ans;
}

int cacl_kpm(const vector<string>& tpl, const vector<string>& est, int minutes) {
  int sum = 0;
  for(int i=0; i<tpl.size(); ++i) {
    sum += calc_correct_ch(tpl[i], est[i]);
  }
  return static_cast<int>(sum * 60.0 / minutes + 0.5);
}

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  vector<string> tpl;
  vector<string> est;
  string line;
  while(getline(cin, line), line != "EOF") {
    tpl.push_back(line);
  }
  while(getline(cin, line), line != "EOF") {
    est.push_back(line);
  }

  int minutes;
  cin >> minutes;

  cout << cacl_kpm(tpl, est, minutes) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}