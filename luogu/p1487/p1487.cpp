#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getMaximum(int s, vector<int>& y) {
  sort(y.begin(), y.end());
  int count = 0;
  for (int i = 0; i < y.size(); ++i) {
    if (s >= y[i]) {
      s -= y[i];
      ++count;
    } else {
      break;
    }
  }
  return count;
}

int main() {
  int n, s;
  int a, b;
  vector<int> y;

  cin >> n >> s;
  cin >> a >> b;
  for (int i = 0; i < n; ++i) {
    int height, cost;
    cin >> height >> cost;
    if (height > a + b) continue;
    y.push_back(cost);
  }

  cout << getMaximum(s, y) << endl;
  return 0;
}
