#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string info;

  string line;
  while (getline(cin, line)) {
    info += line;
    if (find(line.begin(), line.end(), 'E') != line.end()) break;
  }
  size_t i = 0;
  int p1 = 0, p2 = 0;
  while (i < info.size()) {
    if (info[i] == 'E')
      break;
    else if (info[i] == 'W') {
      if (p1 >= 10 && p1 - p2 >= 1) {
        cout << p1 + 1 << ":" << p2 << endl;
        p1 = p2 = 0;
      } else {
        p1++;
      }
    } else if (info[i] == 'L') {
      if (p2 >= 10 && p2 - p1 >= 1) {
        cout << p1 << ":" << p2 + 1 << endl;
        p1 = p2 = 0;
      } else {
        p2++;
      }
    }
    ++i;
  }
  cout << p1 << ":" << p2 << endl;
  cout << endl;

  i = 0;
  p1 = p2 = 0;
  while (i < info.size()) {
    if (info[i] == 'E')
      break;
    else if (info[i] == 'W') {
      if (p1 >= 20 && p1 - p2 >= 1) {
        cout << p1 + 1 << ":" << p2 << endl;
        p1 = p2 = 0;
      } else {
        p1++;
      }
    } else if (info[i] == 'L') {
      if (p2 >= 20 && p2 - p1 >= 1) {
        cout << p1 << ":" << p2 + 1 << endl;
        p1 = p2 = 0;
      } else {
        p2++;
      }
    }
    ++i;
  }
  cout << p1 << ":" << p2 << endl;
  return 0;
}
