#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = n; i >= 0; --i) {
    int temp;
    cin >> temp;
    if (i == 0) {
      if (temp > 0) {
        cout << "+" << temp;
      } else if (temp < 0) {
        cout << temp;
      }
      continue;
    }
    if (i == 1) {
      if (temp < 0) {
        if (temp == -1)
          cout << "-x";
        else
          cout << temp << "x";
      } else if (temp > 0) {
        if (i == n) {
          if (temp == 1)
            cout << "x";
          else
            cout << temp << "x";
        } else {
          if (temp == 1)
            cout << "+x";
          else
            cout << "+" << temp << "x";
        }
      }
      continue;
    }
    if (temp < 0) {
      if (temp == -1)
        cout << "-x^" << i;
      else
        cout << temp << "x^" << i;
    } else if (temp > 0) {
      if (i == n) {
        if (temp == 1)
          cout << "x^" << i;
        else
          cout << temp << "x^" << i;
      } else {
        if (temp == 1)
          cout << "+x^" << i;
        else
          cout << "+" << temp << "x^" << i;
      }
    }
  }
  cout << endl;
  return 0;
}
