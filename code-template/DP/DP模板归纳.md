# DP模板归纳
## 最大/小路径类

### 问题类型

给定一个目标，寻找达成目标的最大/小的花费/路径/和。

### 解决套路

对当前状态，在所有可行的路径中挑选一个最小/最大的路劲，并累计该值到当前状态。

状态转移方程：

`routes[i] = min(routes[i-1], routes[i-2], ... , routes[i-k]) + cost[i]`


### 代码模板

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
  - [Easy]746
  - [Medium]64
  - [Medium]120
  - [Medium]221
  - [Medium]279
  - [Medium]332
  - [Medium]474
  - [Medium]650
  - [Medium]931
  - [Medium]983
  - [Hard]1240
  - [Hard]174
  - [Hard]871

## N种方法类

### 问题类型
给定一个目标，计算达成目标有多少种方法。

### 解决套路
对当前状态，使用过往状态累加所有可行的方法。

状态转移方程：

`routes[i] = routes[i-1] + routes[i-2], ... , + routes[i-k]`

### 代码模板

```cpp
for (int i = 1; i <= target; ++i) {
   for (int j = 0; j < ways.size(); ++j) {
       if (ways[j] <= i) {
           dp[i] += dp[i - ways[j]];
       }
   }
}
 
return dp[target]
```

### 问题收集

- LeetCode:
  - [Medium]62
  - [Medium]63
  - [Easy]70
  - [Medium]377
  - [Medium]416
  - [Medium]494
  - [Medium]576
  - [Medium]673
  - [Medium]688
  - [Medium]790
  - [Medium]801
  - [Medium]808
  - [Medium]935
  - [Medium]1155