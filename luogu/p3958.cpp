#include <iostream>

#define MAXN 1005

struct Sphere {
    long long x = 0;
    long long y = 0;
    long long z = 0;
    long long r = 0;

    void reinit(long long r) {
        x = y = z = 0;
        this->r = r;
    }
    bool adjacent(const Sphere& other);
};

bool Sphere::adjacent(const Sphere& other) {
    return (this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y) + (this->z - other.z) * (this->z - other.z) <= (this->r + other.r) * (this->r + other.r);
}

int fa[MAXN], rank[MAXN];
Sphere sphere[MAXN];

inline void init(int n) {
    for(int i=0; i<n; ++i) {
        fa[i] = i;
        rank[i] = 1;
    }
    fa[1001] = 1001; // bottom
    fa[1002] = 1002; // top
}

int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j) {
    int x = find(i), y = find(j);
    if(rank[x] <= rank[y]) {
        fa[x] = y;
    } else {
        fa[y] = x;
    }
    if(rank[x] == rank[y] && x != y) {
        rank[y]++;
    }
}

int main()
{
    long long T, n, h;
    std::cin >> T;
    for(int i=0; i<T; ++i) {
        long long r;
        std::cin >> n >> h >> r;
        for(int j=0; j<MAXN; ++j) {
            sphere[j].reinit(r);
        }
        init(n);
        for(int j=0; j<n; ++j) {
            std::cin >> sphere[j].x >> sphere[j].y >> sphere[j].z;
        }

        for(int j=0; j<n; ++j) {
            if(sphere[j].z <= r) {
                merge(j, 1001);
            }
            if(sphere[j].z + r >= h) {
                merge(j, 1002);
            }
        }
        for(int j=0; j<n; ++j) {
            for(int k=j+1; k<n; ++k) {
                if(sphere[j].adjacent(sphere[k])) {
                    merge(j, k);
                }
            }
        }
        std::cout << (find(1001) == find(1002) ? "Yes\n" : "No\n");
    }
    return 0;    
}