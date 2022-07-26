#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word2.size()+1, vector<int>(word1.size()+1, INT32_MAX));
    dp[0][0] = 0;
    for(int k=1; k<=word1.size(); ++k) {
      dp[0][k] = k;
    }
    for(int k=1; k<=word2.size(); ++k) {
      dp[k][0] = k;
    }

    for(int i=1; i<=word2.size(); ++i) {
      for(int j=1; j<=word1.size(); ++j) {
        // replace
        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (word1[j-1] == word2[i-1] ? 0 : 1));
        // del
        dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
        // add
        dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
      }
    }

    return dp[word2.size()][word1.size()];
  }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  string s1, s2;
  cin >> s1 >> s2;
  cout << Solution{}.minDistance(s1, s2);
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}