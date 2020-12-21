#include <bits/stdc++.h>

using namespace std;

int a[100], b[100], c[100], d[100];
int sum = 0;
int n;

void print() {
    if(sum < 3)
    {
        for(int k=0;k<n;k++)
            cout << a[k] + 1 << " ";
        cout << endl;
    }
    sum++;
}

void queen(int i) {
    if(i >= n) {
        print();
        return ;
    }
    for(int j=0; j<n; j++){
        if(b[j] == 0 && c[i+j] == 0 && d[i-j+n] == 0) {
            a[i] = j;       // 第i行占领第j列
            b[j] = 1;       // 第j列被占领
            c[i+j] = 1;     // 占领左下到右上的对角线
            d[i-j+n] = 1;   // 占领左上到右下的对角线
            queen(i+1);
            b[j] = 0;
            c[i+j] = 0;
            d[i-j+n] = 0;
        }
    }
}

int main() {
    cin >> n;
    queen(0);
    cout << sum << endl;
    return 0;
}