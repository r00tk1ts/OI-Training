#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

struct item {
    int weight;
    int value;
};

int max_weight(const vector<item>& items, int weight) {
    int num = items.size();
    vector<vector<int>> dp(items.size()+1, vector<int>(weight+1));

    for(int i=1; i<=num; ++i) {
        for(int j=1; j<=weight; ++j) {
            auto w = items[i-1].weight;
            for(int k=0; k<=j/w; ++k) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-k*w] + k * items[i-1].value);
            }
        }
    }
    return dp[num][weight];
}

int max_weight_v2(const vector<item>& items, int weight) {
    int num = items.size();
    vector<vector<int>> dp(items.size()+1, vector<int>(weight+1));

    for(int i=1; i<=num; ++i) {
        for(int j=1; j<=weight; ++j) {
            if(j < items[i-1].weight) {
                dp[i][j] = dp[i-1][j];
            } else {
                // 和01背包的区别就在于，第二个的一维要取i而不是i-1，这意味着此前可以取任意数量的第i个元素，而不是0个
                dp[i][j] = max(dp[i-1][j], dp[i][j-items[i-1].weight] + items[i-1].value);
            }
        }
    }
    return dp[num][weight];
}

// 状态压缩DP，滚动数组一维化
int max_weight_v3(const vector<item>& items, int weight) {
    int num = items.size();
    vector<int> dp(weight+1);

    for(int i=0; i<num; ++i) {
        for(int j=items[i].weight; j<=weight; ++j) {
            dp[j] = max(dp[j], dp[j-items[i].weight] + items[i].value);
        }
    }
    return dp[weight];
}

int main() {
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif

    int weight, num;
    cin >> weight >> num;

    vector<item> items(num);
    for (int i=0; i<num; ++i) {
        cin >> items[i].weight >> items[i].value;
    }
    cout << max_weight(items, weight) << endl;
    cout << max_weight_v2(items, weight) << endl;
    cout << max_weight_v3(items, weight) << endl;

#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<" ms"<<endl;
#endif
    return 0;
}