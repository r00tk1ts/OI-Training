#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double distance = 7.0;
  int s, x;
  cin >> s >> x;

  double sum = 0;
  while (sum < s - x) {
    sum += distance;
    distance *= 0.98;
  }
  if (distance <= s + x - sum)
    cout << "y" << endl;
  else
    cout << "n" << endl;
  return 0;
}
