#include <cassert>
#include <iostream>

using namespace std;

string isValidIsbn(const string& isbn) {
  string ret(isbn.begin(), isbn.end() - 1);

  assert(isbn.size() == 13);

  unsigned int sum = 0;
  int index = 1;
  for (size_t i = 0; i < isbn.size(); ++i) {
    if (i == 1 || i == 5 || i == 11) {
      assert(isbn[i] == '-');
    } else if (i == 12) {
      if (sum % 11 == 10) {
        if (isbn[i] == 'X')
          return "Right";
        else
          return ret + "X";
      } else {
        if (isbn[i] - '0' == sum % 11)
          return "Right";
        else
          return ret.append(1, '0' + sum % 11);
      }
    } else {
      assert('0' <= isbn[i] && isbn[i] <= '9');
      sum += index * (isbn[i] - '0');
      index++;
    }
  }
  // never through here
  return "";
}

int main() {
  string isbn;
  cin >> isbn;

  cout << isValidIsbn(isbn) << endl;

  return 0;
}
