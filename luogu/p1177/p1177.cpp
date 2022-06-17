#include <bits/stdc++.h>

using namespace std;

int vec[1000001];

void quicksort(int begin, int end) {
  if (begin >= end) return;
  int mid = vec[(begin + end) / 2];
  int i = begin, j = end;

  do {
    while (vec[i] < mid) ++i;
    while (vec[j] > mid) --j;
    if (i <= j) {
      swap(vec[i], vec[j]);
      ++i;
      --j;
    }
  } while (i <= j);
  quicksort(begin, j);
  quicksort(i, end);
}

int main() {
  int number;

  cin >> number;
  for (int i = 0; i < number; ++i) {
    cin >> vec[i];
  }

  quicksort(0, number - 1);
  for (int i = 0; i < number; ++i) {
    cout << vec[i] << " ";
  }
  cout << endl;
  return 0;
}
