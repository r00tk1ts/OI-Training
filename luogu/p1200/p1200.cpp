#include <iostream>

using namespace std;

bool isMatch(const string& ufo, const string& group) {
  unsigned int n1 = 1, n2 = 1;
  for (auto& c : ufo) {
    n1 *= c - 'A' + 1;
  }
  for (auto& c : group) {
    n2 *= c - 'A' + 1;
  }
  if (n1 % 47 == n2 % 47)
    return true;
  else
    return false;
}

int main() {
  string ufo, group;
  cin >> ufo >> group;

  if (isMatch(ufo, group))
    cout << "GO" << endl;
  else
    cout << "STAY" << endl;
  return 0;
}
