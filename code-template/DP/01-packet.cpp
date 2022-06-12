#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

struct item {
    int weight;
    int value;
};

// 标准的01背包DP模板
// 时间复杂度O(items.size() * weight)
// 空间复杂度O(items.size() * weight)
int max_weight(const vector<item> &items, int weight) {
    int number = items.size();
    vector<vector<int>> dp(number+1, vector<int>(weight+1));

    /* 
     * 二维DP: dp[i][j]表示当背包重j时，从前i个物品中挑选可以得到的最大价值
     *        因此dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1].weight] + items[i-1].value)
     *        对于第i个物品，要么不取，要么取，不取则继承dp[i-1][j]，取的话相当于背包重量变成了（j-第i个物品的重量）
     */
    for(int i=1; i<=number; ++i) {
        for(int j=1; j<=weight; ++j) {
            if(j < items[i-1].weight) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1].weight] + items[i-1].value);
            }
        }
    }
    return dp[number][weight];
}

// 状态压缩DP，空间复杂度降低到O(weight)
int max_weight_v2(const vector<item> &items, int weight) {
    int number = items.size();
    vector<int> dp(weight+1, 0);

    for(int i=0; i<number; ++i) {
        // 因为dp[j-items[i].weight]需要的上一轮的结果，所以必须得倒着处理才能保证不被本轮结果覆盖
        // 此外，第一轮倒着处理也并不影响结果的正确性
        for(int j=weight; j>=items[i].weight; --j) {
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
    for(int i=0; i<num; ++i) {
        cin >> items[i].weight >> items[i].value;
    }

    cout << max_weight(items, weight) << endl;
    cout << max_weight_v2(items, weight) << endl;
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<" ms"<<endl;
#endif
    return 0;
}