#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  m *= 1.5;

  map<int, vector<int> > v;
  for (int i = 0; i < n; ++i) {
    int k, s;
    cin >> k >> s;
    v[s].push_back(k);
  }

  int count = m;
  int score = 0;
  for (auto iter = v.rbegin(); iter != v.rend(); ++iter) {
    count -= iter->second.size();
    if (count <= 0) {
      score = iter->first;
      count = m - count;
      break;
    }
  }
  cout << score << " " << count << endl;

  for (auto iter = v.rbegin(); iter != v.rend(); ++iter) {
    sort(iter->second.begin(), iter->second.end());
    for (auto& elem : iter->second) {
      cout << elem << " " << iter->first << endl;
      count--;
    }
    if (count == 0) break;
  }
  return 0;
}
