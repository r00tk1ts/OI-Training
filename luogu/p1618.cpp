#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool exist = false;

  for (int i = 123; i <= 327; ++i) {
    int j = i * b / a;
    int k = i * c / a;
    if (k > 987) continue;
    if ((i % 10 + i / 10 % 10 + i / 100 % 10 + j % 10 + j / 10 % 10 + j / 100 % 10 + k % 10 +
             k / 10 % 10 + k / 100 % 10 ==
         45) &&
        ((i % 10) * (i / 10 % 10) * (i / 100 % 10) * (j % 10) * (j / 10 % 10) * (j / 100 % 10) *
             (k % 10) * (k / 10 % 10) * (k / 100 % 10) ==
         2 * 3 * 4 * 5 * 6 * 7 * 8 * 9)) {
      cout << i << " " << j << " " << k << endl;
      exist = true;
    }
  }
  if (exist == false) cout << "No!!!" << endl;
  return 0;
}
