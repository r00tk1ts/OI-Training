#include<bits/stdc++.h>

using namespace std;

struct peanut{
    int x, y, time, count;    
};

peanut p[400];

int main()
{
    int m, n, k = 0;

    cin >> m >> n >> k;
    int index = 0;
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            int temp = 0;
            
            cin >> temp;
            if(temp > 0) {
                p[index].x = i;
                p[index].y = j;
                p[index].count = temp;
                p[index].time = 0;    
                ++index;
            }            
        }    
    }    

    // swap sort
    for(int i=0; i<index; ++i) {
        for(int j=i+1; j<index; ++j) {
            if(p[i].count < p[j].count) {
                swap(p[i], p[j]);    
            }    
        }    
    }

    int depth = 0, sum = 0;
    for(int i=0; i<index; ++i) {
        depth = p[i].x;
        if(i == 0) {
            p[i].time = p[i].x + 1;    
        } else {
            p[i].time = p[i-1].time + abs(p[i].x - p[i-1].x) + abs(p[i].y - p[i-1].y) + 1;    
        }

        if(p[i].time + depth <= k) {
            sum += p[i].count;
        }
    }
    cout << sum << endl;
    return 0;    
}
