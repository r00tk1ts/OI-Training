#include <chrono>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

bool is_valid_date(const string& date) {
  int year = stoi(date.substr(0, 4));
  int month = stoi(date.substr(4, 2));
  int day = stoi(date.substr(6, 2));

  if(month == 0 || month > 13) return false;
  bool flag = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;
  switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if(day == 0 || day > 31) return false;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if(day == 0 || day > 30) return false;
      break;
    case 2:
      if (day == 0 || day > 28 + (flag ? 1 : 0)) return false;
      break;
    default:
      return false;
  }
  return true;
}

bool is_palindrome(const string& date) {
  int left = 0, right = date.size()-1;
  while(left < right) {
    if (date[left] != date[right]) return false;
    left++, right--;
  }
  return true;
}

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif

  int begin, end;
  cin >> begin >> end;

  int s[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
  int ans = 0;
  for(int i=1; i<=12; ++i) {
    for(int j=1; j<=s[i]; ++j) {
      // 算出回文数的年份
      auto year = (j%10)*1000 + (j/10)*100+(i%10)*10+(i/10);
      auto date = year*10000 + i*100 + j; 
      if (date < begin || date > end) continue;
      ans++;
    }
  }
  cout << ans << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}