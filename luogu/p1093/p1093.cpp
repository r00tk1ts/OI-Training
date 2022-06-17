#include <bits/stdc++.h>

using namespace std;

struct student {
  int num;
  int chinese;
  int math;
  int english;
  int sum;
};

student s[301];

bool sort_student(const student& a, const student& b) {
  if (a.sum == b.sum) {
    if (a.chinese == b.chinese)
      return a.num < b.num;
    else
      return a.chinese > b.chinese;
  }
  return a.sum > b.sum;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    s[i].num = i;
    cin >> s[i].chinese >> s[i].math >> s[i].english;
    s[i].sum = s[i].chinese + s[i].math + s[i].english;
  }
  sort(s + 1, s + n + 1, sort_student);
  for (int i = 1; i <= 5; ++i) {
    cout << s[i].num << " " << s[i].sum << endl;
  }
  return 0;
}
