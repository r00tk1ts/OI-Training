#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <climits>

using namespace std;

const int maxn = 1e5 + 5;

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int n, s1, s2, x, sum, m = INT_MIN, total = 0;
  char a, b;
  string name, m_name;

  cin >> n;
  for(int i=1; i<=n; ++i) {
    sum = 0;
    cin >> name >> s1 >> s2 >> a >> b >> x;
    if(s1 > 80 && x > 0) sum += 8000;
    if(s1 > 85 && s2 > 80) sum += 4000;
    if(s1 > 90) sum += 2000;
    if(s1 > 85 && b == 'Y') sum += 1000;
    if(s2 > 80 && a == 'Y') sum += 850;
    total += sum;
    if(sum > m) {
      m_name = name;
      m = sum;
    }
  }
  cout << m_name << "\n" << m << "\n" << total << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}