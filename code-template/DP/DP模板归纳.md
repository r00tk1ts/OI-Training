# DP模板归纳
## 达成目标的最大/最小路径

### 问题类型

给定一个目标，寻找达成目标的最大/最小的花费/路径/和。

### 解决套路

对当前状态，在所有可行的路径中挑选一个最小/最大的路劲，并累计该值到当前状态。

伪代码：
```
routes[i] = min(routes[i-1], routes[i-2], ... , routes[i-k]) + cost[i]
```

### 模板代码

从1到target自底向上递推：
```cpp
for (int i = 1; i <= target; ++i) {
   for (int j = 0; j < ways.size(); ++j) {
       if (ways[j] <= i) {
           dp[i] = min(dp[i], dp[i - ways[j]] + cost / path / sum) ;
       }
   }
}
 
return dp[target]
```

### 问题收集

- LeetCode:
  - 64
  