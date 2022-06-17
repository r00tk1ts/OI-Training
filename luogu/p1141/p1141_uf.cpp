/* H_Bryan的循环版本并查集题解 */
#include <bits/stdc++.h>

using namespace std;
int f[1000005], h[1000005], n;  // f[i]表示i节点的父节点,
                                // h[i]表示i节点及其子节点的连通块数
char s[2][1005];  //滚动数组
int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}  //查
void unionn(int x, int y)  //并
{
  int r1 = find(x), r2 = find(y);
  if (r1 != r2) h[r1] += h[r2], f[r2] = f[r1];
}
int main() {
  int t;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i & 1]);
    for (int j = 0; j < n; j++) {
      f[i * n + j] = i * n + j, h[i * n + j] = 1;  //构造映射
      if (i != 0 && s[(i - 1) & 1][j] != s[i & 1][j]) unionn((i - 1) * n + j, i * n + j);
      if (j != 0 && s[i & 1][j - 1] != s[i & 1][j]) unionn(i * n + j, i * n + j - 1);
    }
  }
  int i, j;
  while (t--) {
    scanf("%d%d", &i, &j);
    printf("%d\n", h[find((i - 1) * n + j - 1)]);
  }
  return 0;
}