#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

struct item {
    int weight;
    int value;
    int count;
};

// 标准的多重背包DP模板
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
                auto w = items[i-1].weight;
                for(int k=1; k<items[i-1].count && k<=j/w; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k*w] + k * items[i-1].value);
                }
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
            auto w = items[i].weight;
            for(int k=1; k<items[i].count && k<=j/w; ++k) {
                dp[j] = max(dp[j], dp[j-k*w] + k * items[i].value);
            }
        }
    }
    return dp[weight];
}

// 多重背包二进制优化，每种物品count个拆分成1,2,4,8...(min(2^k, left))
// n个物品m，拆分成1个m_1, 1个m_2, 1个m_4……1个m_left，任意数量都可以用二进制化的单个物品凑出来
// 于是转换成标准的01背包
// 状态压缩DP，空间复杂度降低到O(weight)
vector<item> binary_convert(const vector<item> &items);

int max_weight_v3(const vector<item> &items, int weight) {
    vector<int> dp(weight+1, 0);

    auto new_items = binary_convert(items);
    int number = new_items.size();
    for(int i=0; i<number; ++i) {
        for(int j=weight; j>=new_items[i].weight; --j) {
            dp[j] = max(dp[j], dp[j-new_items[i].weight] + new_items[i].value);
        }
    }
    return dp[weight];
}

vector<item> binary_convert(const vector<item> &items) {
    vector<item> res;
    for(auto& elem : items) {
        int count = elem.count;
        for(int s=0; count>=(1<<s); s+=1){
            res.emplace_back(item{elem.weight * (1 << s), elem.value * (1 << s), 1});
            count -= 1 << s;
        } 
        // deal with rest 
        if(count) {
            res.emplace_back(item{elem.weight * count, elem.value * count, 1});
        }
    }
    return res;
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
    cin >> num >> weight;
    vector<item> items(num);
    for(int i=0; i<num; ++i) {
        cin >> items[i].weight >> items[i].value >> items[i].count;
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