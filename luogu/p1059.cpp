#include <bits/stdc++.h>

using namespace std;

int main() {
  /*
  set<int> s;
  int number;
  cin >> number;
  for(int i=0; i<number; ++i)
  {
          int temp;
          cin >> temp;
          s.insert(temp);
  }
  cout << s.size() << endl;
  for(auto &elem : s)
          cout << elem << " ";
  cout << endl;
  */

  bool bitmap[1001] = {false};
  int number;
  cin >> number;
  int count = 0;
  for (int i = 0; i < number; ++i) {
    int temp;
    cin >> temp;
    if (bitmap[temp]) continue;
    bitmap[temp] = true;
    ++count;
  }

  cout << count << endl;
  for (int i = 0; i < 1001; ++i) {
    if (bitmap[i]) cout << i << " ";
  }
  cout << endl;
  return 0;
}
