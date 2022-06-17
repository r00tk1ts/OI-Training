#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    vector<bool> dp(1501, false);
    dp[0] = true;
    int sum = 0;
    for (auto stone : stones) {
      sum += stone;
      for (int i = min(1500, sum); i >= stone; --i) dp[i] = dp[i] | dp[i - stone];
    }
    for (int i = sum / 2; i >= 0; --i)
      if (dp[i]) return sum - i - i;
    return 0;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> stones(n);
  for (int i = 0; i < n; ++i) {
    cin >> stones[i];
  }
  Solution s;
  cout << s.lastStoneWeightII(stones) << endl;
  return 0;
}