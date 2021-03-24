#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(unsigned int n) {
  if (n <= 1) return false;
  for (unsigned int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  for (int i = 2; i < n - 4; ++i) {
    if (isPrime(i)) {
      for (int j = 2; j < n - 4; ++j) {
        if (isPrime(j) && isPrime(n - i - j)) {
          cout << i << " " << j << " " << n - i - j << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
