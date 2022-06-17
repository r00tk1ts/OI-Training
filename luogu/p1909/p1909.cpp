#include <iostream>

using namespace std;

int main() {
  int n;
  int money = 0;
  cin >> n;
  for (int i = 0; i < 3; ++i) {
    int num, price;
    cin >> num >> price;
    int temp = price * (n / num + (n % num ? 1 : 0));
    if (money == 0 || money > temp) money = temp;
  }
  cout << money;
  return 0;
}
