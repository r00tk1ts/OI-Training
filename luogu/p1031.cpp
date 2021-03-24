#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, sum = 0;
  vector<int> v;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    sum += temp;
    v.push_back(temp);
  }
  sum /= n;
  int count = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (v[i] != sum) {
      v[i + 1] += v[i] - sum;
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
