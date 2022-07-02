#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
    double average(vector<int>& salary) {
      sort(salary.begin(), salary.end());
      return static_cast<double>(accumulate(salary.begin()+1, salary.end()-1, 0)) / (salary.size()-2);
    }
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int n;
  cin >> n;
  vector<int> salary(n);
  for(int i=0; i<n; ++i) cin >> salary[i];
  cout << Solution{}.average(salary);
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}