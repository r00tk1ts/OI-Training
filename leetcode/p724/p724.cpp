#include <chrono>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    for(int i=0; i<nums.size(); ++i) {
      update(i+1, nums[i]);
    }

    for(int i=0; i<nums.size(); ++i) {
      int left_sum = query(0, i);
      int right_sum = query(i+1, nums.size());
      //cout << i << " " << left_sum << " " << right_sum << endl;
      if (left_sum == right_sum) return i;
    }
    return -1;
  }

private:
  void update(int n, int d) {
    for(; n<maxn; n+=n&-n) {
      tree[n] += d;
    }
  }

  int query(int n) {
    int sum = 0;
    for(; n>0; n-=n&-n) {
      sum += tree[n];
    }
    return sum;
  }

  int query(int a, int b) { return query(b) - query(a); }
private:
  int tree[maxn] = {0};
};

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<v.size(); ++i) cin >> v[i];
  cout << Solution{}.pivotIndex(v) << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}