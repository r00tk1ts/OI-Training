#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (dungeon[m - 1][n - 1] >= 0)
        {
            dp[m - 1][n - 1] = 1;
        }
        else
        {
            dp[m - 1][n - 1] = 1 - dungeon[m - 1][n - 1];
        }

        for (int i = m - 2; i >= 0; --i)
        {
            if (dungeon[i][n - 1] < dp[i + 1][n - 1])
            {
                dp[i][n - 1] = dp[i + 1][n - 1] - dungeon[i][n - 1];
            }
            else
            {
                dp[i][n - 1] = 1;
            }
        }
        for (int j = n - 2; j >= 0; --j)
        {
            if (dungeon[m - 1][j] < dp[m - 1][j + 1])
            {
                dp[m - 1][j] = dp[m - 1][j + 1] - dungeon[m - 1][j];
            }
            else
            {
                dp[m - 1][j] = 1;
            }
        }

        for (int i = m - 2; i >= 0; --i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                int up, left;
                if (dungeon[i][j] < dp[i + 1][j])
                {
                    up = dp[i + 1][j] - dungeon[i][j];
                }
                else
                {
                    up = 1;
                }

                if (dungeon[i][j] < dp[i][j + 1])
                {
                    left = dp[i][j + 1] - dungeon[i][j];
                }
                else
                {
                    left = 1;
                }

                dp[i][j] = min(up, left);
            }
        }
        return dp[0][0];
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dungeon(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> dungeon[i][j];
        }
    }

    Solution s;
    cout << s.calculateMinimumHP(dungeon) << endl;
    return 0;
}