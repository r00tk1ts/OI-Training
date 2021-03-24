#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int n) {
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

void countPrime(int v[20], int length, int pos, int k, int sum, int& count) {
  if (k == 0) {
    if (isPrime(sum)) {
      ++count;
    }
    return;
  }
  if (pos == length) return;
  countPrime(v, length, pos + 1, k - 1, sum + v[pos], count);
  countPrime(v, length, pos + 1, k, sum, count);
}

int main() {
  int n, k;
  int v[20] = {0};

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int count = 0;
  countPrime(v, n, 0, k, 0, count);
  cout << count << endl;
  return 0;
}
