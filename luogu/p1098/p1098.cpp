#include <bits/stdc++.h>

using namespace std;

int main() {
  int p1, p2, p3;
  cin >> p1 >> p2 >> p3;

  string orig;
  cin >> orig;

  int pos = 0;
  while (pos < orig.size()) {
    if (orig[pos] == '-') {
      if (pos == 0 || pos + 1 == orig.size()) {
        cout << orig[pos];
        pos++;
        continue;
      }
      char left = orig[pos - 1];
      char right = orig[pos + 1];
      if (left >= right || (left <= '9' && 'a' <= right)) {
        cout << orig[pos];
      } else {
        left++;
        string temp;
        while (left < right) {
          if ('a' <= left && right <= 'z') {
            if (p1 == 1) {
              for (int i = 0; i < p2; ++i) {
                temp += left;
              }
            } else if (p1 == 2) {
              for (int i = 0; i < p2; ++i) {
                temp += static_cast<char>(left - 'a' + 'A');
              }
            } else if (p1 == 3) {
              for (int i = 0; i < p2; ++i) {
                temp += "*";
              }
            }
          } else if ('0' <= left && right <= '9') {
            if (p1 == 1 || p1 == 2) {
              for (int i = 0; i < p2; ++i) {
                temp += left;
              }
            } else if (p1 == 3) {
              for (int i = 0; i < p2; ++i) {
                temp += "*";
              }
            }
          }
          left++;
        }
        if (p3 == 2) {
          for (auto iter = temp.rbegin(); iter != temp.rend(); ++iter) {
            cout << *iter;
          }
        } else if (p3 == 1) {
          cout << temp;
        }

        if (temp.empty() && orig[pos - 1] + 1 != orig[pos + 1]) cout << "-";
      }
    } else {
      cout << orig[pos];
    }
    pos++;
  }
  cout << endl;
  return 0;
}
