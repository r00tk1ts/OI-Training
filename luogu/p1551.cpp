#include <iostream>
#include <sstream>

#define MAXN 5005
int fa[MAXN], rank[MAXN];

inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        rank[i] = 1;
    }
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++;
}

int main()
{
    int n, m, p, x, y;
    std::cin >> n >> m >> p;
    std::stringstream ss;
    
    init(n);
    
    for (int i = 0; i < m; ++i)
    {
        std::cin >> x >> y;
        merge(x, y);
    }
    for (int i = 0; i < p; ++i)
    {
        std::cin >> x >> y;
        ss << (find(x) == find(y) ? "Yes\n" : "No\n");
    }
    std::cout << ss.str();
    return 0;
}