#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100000];

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }    

    int segment = 1;
    int sum = 0;
    for(int i=0; i<n; ++i) {
        if(sum + arr[i] <= m) {
            sum += arr[i];
        } else {
            sum = arr[i];
            segment++;
        }
    }
    cout << segment << endl;
    return 0;
}