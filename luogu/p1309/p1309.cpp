#include <bits/stdc++.h>

using namespace std;

struct Item {
  int score;
  int num;
  int w;
};

Item g_total[200001];
Item g_win[100001];
Item g_lose[100001];

bool compare(const Item& a, const Item& b) {
  if (a.score == b.score) return a.num < b.num;
  return a.score > b.score;
}

void merge(int n) {
  int i = 1;
  int j = 1;
  int pos = 1;
  while (i <= n && j <= n) {
    if (compare(g_win[i], g_lose[j])) {
      g_total[pos] = g_win[i];
      ++i;
      ++pos;
    } else {
      g_total[pos] = g_lose[j];
      ++j;
      ++pos;
    }
  }
  while (i <= n) {
    g_total[pos] = g_win[i];
    ++i;
    ++pos;
  }
  while (j <= n) {
    g_total[pos] = g_lose[j];
    ++j;
    ++pos;
  }
}

int main() {
  int n, r, q;
  cin >> n >> r >> q;
  n *= 2;
  for (int i = 1; i <= n; ++i) {
    cin >> g_total[i].score;
    g_total[i].num = i;
  }

  for (int i = 1; i <= n; ++i) {
    cin >> g_total[i].w;
  }

  sort(g_total + 1, g_total + n + 1, compare);

  for (int i = 0; i < r; ++i) {
    int pos = 1;
    for (int j = 1; j <= n; j += 2) {
      // diff for each pair
      if (g_total[j].w > g_total[j + 1].w) {
        g_total[j].score++;
        g_win[pos] = g_total[j];
        g_lose[pos] = g_total[j + 1];
      } else {
        g_total[j + 1].score++;
        g_win[pos] = g_total[j + 1];
        g_lose[pos] = g_total[j];
      }
      ++pos;
    }
    merge(pos - 1);
  }
  cout << g_total[q].num << endl;
  return 0;
}
