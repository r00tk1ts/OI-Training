#include <bits/stdc++.h>

using namespace std;

int f[1000000];
int h[1000000];
int n,m;
int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char s[1000][1000];

int find(int node) {
    if(f[node] == node)
        return node;
    else 
        return find(f[node]);
}

void union_c(int a, int b) {
    int p = find(a), q = find(b);
    if(p != q) {
        f[q] = f[p];
        h[p] += h[q];
    }
}

int dfs(int x,int y)
{
    if(f[x*n+y] != -1)
        return find(x*n+y);
    f[x*n+y] = x * n + y;
    h[x*n+y] = 1;
    for(int k=0;k<4;k++)
    {
        int i = x + step[k][0], j = y + step[k][1];
        if(i >= 0 && i < n && j >= 0 && j < n && s[x][y] != s[i][j])
            union_c(x*n+y, dfs(i,j));
    }
    return find(x*n+y);
}

int main()
{
    cin >> n >> m;
    memset(f, -1, sizeof(int)*n*n);
    for(int i=0; i<n; ++i) {
        cin >> s[i];
    }

    while(m--) {
        int i, j;
        cin >> i >> j;
        cout << h[dfs(i-1, j-1)] << endl;
    }
    return 0;
}