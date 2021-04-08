#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    // dp[i]表示加i次油所能走得最远的距离
    // 我们需要找到最小的i，使得dp[i] >= target
    vector<int> dp(stations.size() + 1);
    dp[0] = startFuel;
    for (int i = 0; i < stations.size(); ++i) {
      for (int j = i; j >= 0; --j) {
        if (dp[j] >= stations[i][0]) {
          dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
        }
      }
    }

    for (size_t i = 0; i < dp.size(); ++i) {
      if (dp[i] >= target) return i;
    }
    return -1;
  }
};

int main() {
  int target, startFuel, number;
  cin >> target >> startFuel >> number;
  vector<vector<int>> stations;
  for (int i = 0; i < number; ++i) {
    int pos, fuel;
    cin >> pos >> fuel;
    stations.emplace_back(vector<int>{pos, fuel});
  }
  Solution s;
  cout << s.minRefuelStops(target, startFuel, stations) << endl;
  return 0;
}