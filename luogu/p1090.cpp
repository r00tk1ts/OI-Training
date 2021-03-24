#include <bits/stdc++.h>

using namespace std;

int vec[10001] = {0};

int merge(int start, int end) {
  if (start >= end) return 0;

  vec[start + 1] += vec[start];
  vec[start] = 0;
  int ret = vec[start + 1];
  int pos = 0;
  for (pos = start + 2; pos <= end; ++pos) {
    if (ret < vec[pos]) {
      break;
    }
  }
  for (int i = start + 1; i < pos - 1; ++i) {
    vec[i] = vec[i + 1];
  }
  vec[pos - 1] = ret;
  for (int i = 1; i <= end; ++i) cout << vec[i] << " ";
  cout << endl;
  return ret;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> vec[i];
  }
  sort(vec + 1, vec + n + 1);
  int sum = 0;
  for (int i = 1; i <= n - 1; ++i) {
    sum += merge(i, n);
  }
  cout << sum << endl;
  return 0;
}
