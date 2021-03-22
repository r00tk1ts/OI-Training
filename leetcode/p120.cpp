#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        size_t level = triangle.size();
        vector<vector<int>> dp(level);
        for(size_t i=0; i<dp.size(); ++i) {
            dp[i].resize(i+1, INT_MAX);
        }
        dp[0][0] = triangle[0][0];
        for(size_t i=1; i<level; ++i) {
            for(size_t j=0; j<dp[i].size(); ++j) {
                if(j == 0) {
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                } else if (j == dp[i].size() - 1) {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]; 
                }
            }
        }

        int ret = INT_MAX;
        for(size_t i=0; i<dp[level-1].size(); ++i) {
            ret = min(ret, dp[level-1][i]);
        }
        return ret;
    }
};

int main() {
    size_t level;
    vector<vector<int>> triangle;
    cin >> level;
    triangle.resize(level);
    for(size_t i=0; i<level; ++i) {
        for(size_t j=0; j<i+1; ++j) {
            int temp;
            cin >> temp;
            triangle[i].push_back(temp);
        }
    }

    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}