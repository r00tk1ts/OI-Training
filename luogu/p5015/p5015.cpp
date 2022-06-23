#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int maxn = 1e5 + 5;

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif

  string line;
  getline(cin, line);

  int length = line.size();
  for(auto &ch : line) {
    if (ch == ' ') length--;
  }  
  cout << length << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}