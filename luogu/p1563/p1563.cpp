#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

struct Person {
  int direction;
  string name;
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int n, m;
  cin >> n >> m;

  vector<Person> v;

  for(int i=0; i<n; ++i) {
    Person p;
    cin >> p.direction >> p.name;
    v.emplace_back(std::move(p));
  }

  int pos = 0;
  for(int i=0; i<m; ++i) {
    int dir, step;
    cin >> dir >> step;
    
    // 朝内
    if (v[pos].direction == 0) {
      // 向左
      if (dir == 0) {
        pos = (pos + n - step % n) % n;
      } else {
        pos = (pos + step % n) % n;
      }
    } else {
      // 向左
      if (dir == 0) {
        pos = (pos + step % n) % n;
      } else {
        pos = (pos + n - step % n) % n;
      }
    }
    //cout << pos << "\t" << v[pos].name << endl;
  }
  cout << v[pos].name << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}