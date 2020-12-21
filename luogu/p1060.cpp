#include <bits/stdc++.h>

using namespace std;

int t, m, dp[30005], c[30005], v[1005];

int main()
{
    cin >> t >> m;
    for(int i=1; i<=m; ++i) {
        cin >> c[i] >> v[i];
        v[i] *= c[i];
    }

    for(int i=1; i<=m; ++i) {
        for(int j=t; j-c[i]>=0; --j) {
            dp[j] = max(dp[j], dp[j-c[i]] + v[i]);
        }  
    }
    cout << dp[t] << endl;
    return 0;
}