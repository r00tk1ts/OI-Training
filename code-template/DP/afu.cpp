#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

vector<int> max_value(const vector<vector<int>>& v) {
  vector<int> res;

  for (int i = 0; i < v.size(); ++i) {
    vector<int> dp(v[i].size() + 1);
    dp[0] = 0;
    dp[1] = v[i][0];
    for (int j = 2; j < dp.size(); ++j) {
      dp[j] = max(dp[j - 1], dp[j - 2] + v[i][j - 1]);
    }
    res.push_back(dp[dp.size() - 1]);
  }
  return res;
}

vector<int> max_value2(const vector<vector<int>>& v) {
  vector<int> res;

  for (int i = 0; i < v.size(); ++i) {
    vector<vector<int>> dp(v[i].size() + 1, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = v[i][0];

    for (int j = 2; j < dp.size(); ++j) {
      dp[j][0] = max(dp[j - 1][1], dp[j - 1][0]);
      dp[j][1] = dp[j - 1][0] + v[i][j - 1];
    }
    res.push_back(max(dp[dp.size() - 1][0], dp[dp.size() - 1][1]));
  }
  return res;
}

int main() {
#if defined(LOCAL) || defined(DEBUG)
  freopen("in.txt", "r", stdin);
#ifndef DEBUG
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
#endif

  int count;
  cin >> count;
  vector<vector<int>> v(count);
  for (int i = 0; i < count; ++i) {
    int temp;
    cin >> temp;
    v[i].resize(temp);
    for (int j = 0; j < temp; ++j) {
      cin >> v[i][j];
    }
  }

  auto res = max_value2(v);
  for (auto item : res) cout << item << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << " ms"
       << endl;
#endif
  return 0;
}