#include <bits/stdc++.h>

using namespace std;

int v, n;
int dp[20005], c[35];
int main()
{
    cin >> v >> n;
    for(int i=1; i<=n; ++i) {
        cin >> c[i];
    }

    for(int i=1; i<=n; ++i) {
        for(int j=v; j-c[i]>=0; --j) {
            dp[j] = max(dp[j], dp[j-c[i]] + c[i]);
        }
    }
    cout << v - dp[v] << endl;
    return 0;
}