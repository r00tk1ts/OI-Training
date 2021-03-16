#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        // 初始化第一行
        int sum = 0;
        for(int j=0; j<n; ++j) {
            sum += grid[0][j];
            dp[0][j] = sum;
        }

        // 初始化第一列
        sum = 0;
        for(int i=0; i<m; ++i) {
            sum += grid[i][0];
            dp[i][0] = sum;
        }

        // 状态转移方程：dp[i][j]要么从dp[i][j-1]来，要么从dp[i-1][j]来
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int>> grid(m);
    for(size_t i=0; i<m; ++i) {
        grid[i].resize(n);
    }
    for(int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> grid[i][j];
        }
    }
    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}