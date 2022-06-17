#include <bits/stdc++.h>

using namespace std;

string str[20];
int cnt[20] = {0};
int n, length = 0;
char ch;

int calc_common(const string& s1, const string& s2) {
  for (int i = 1; i < min(s1.length(), s2.length()); ++i) {
    bool flag = true;
    for (int j = 0; j < i; ++j) {
      if (s1[s1.length() - i + j] != s2[j]) flag = false;
    }
    if (flag) return i;
  }
  return 0;
}

void dfs(const string& s, int len) {
  length = max(len, length);
  for (int i = 0; i < n; ++i) {
    if (cnt[i] >= 2) continue;
    int ret = calc_common(s, str[i]);
    if (ret > 0) {
      cnt[i]++;
      dfs(str[i], len + str[i].length() - ret);
      cnt[i]--;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str[i];
  }
  cin >> ch;
  for (int i = 0; i < n; ++i) {
    if (str[i][0] == ch) {
      cnt[i]++;
      dfs(str[i], str[i].length());
      cnt[i]--;
    }
  }
  cout << length << endl;
  return 0;
}