#include <bits/stdc++.h>

using namespace std;

struct Item {
    int price;
    int sum;
};

int n, m;
Item arr[5000];

bool compare(const Item &a, const Item &b) {
    if(a.price != b.price)
        return a.price < b.price;
    else
        return a.sum > b.sum;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        cin >> arr[i].price >> arr[i].sum;
    }
    sort(arr, arr+m, compare);
    int total = 0;
    int price = 0;
    for(int i=0; i<m; ++i) {
        if(total + arr[i].sum <= n) {
            total += arr[i].sum;
            price += arr[i].price * arr[i].sum;
        } else {
            price += (n - total) * arr[i].price;
            break;
        }
    }
    cout << price << endl;
    return 0;
}