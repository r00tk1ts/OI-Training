#include <bits/stdc++.h>

using namespace std;

int main() {
  string crypto;
  string plain;
  string deal;
  map<char, char> mp;

  cin >> crypto >> plain >> deal;
  if (crypto.size() != plain.size()) {
    cout << "Failed" << endl;
    return 0;
  }
  for (size_t i = 0; i < crypto.size(); ++i) {
    if (mp.find(crypto[i]) != mp.end()) {
      if (mp[crypto[i]] == plain[i])
        continue;
      else {
        cout << "Failed" << endl;
        return 0;
      }
    } else {
      mp[crypto[i]] = plain[i];
    }
  }
  if (mp.size() != 26) {
    cout << "Failed" << endl;
    return 0;
  }
  vector<bool> vec(26, false);

  for (int i = 0; i < 26; ++i) {
    vec[mp['A' + i] - 'A'] = true;
  }
  if (find(vec.begin(), vec.end(), false) != vec.end()) {
    cout << "Failed" << endl;
    return 0;
  }
  for (size_t i = 0; i < deal.size(); ++i) {
    cout << mp[deal[i]];
  }
  cout << endl;
  return 0;
}
