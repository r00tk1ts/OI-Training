#include <chrono>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;
double a,b,c,d;

double calc_formula(double x) { return a * pow(x, 3) + b * pow(x, 2) + c * x + d; }

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
  int cnt = 0;

  for(double i=-100; i<=100; i+=1) {
    double left = i, right = i + 1;
    auto x1 = calc_formula(left);
    auto x2 = calc_formula(right);
    
    if (x1 == 0) { 
      printf("%.2lf ", left);
      cnt++;
    }

    if(cnt == 3) break;

    // 说明区间内有根
    if(x1 * x2 < 0) {
      while(right - left >= 0.001) {
        double mid = (left + right) / 2;
        if(calc_formula(mid) * calc_formula(right) <= 0) {
          left = mid;
        } else {
          right = mid;
        }
      }
      printf("%.2lf ", right);
      cnt++;
    }
  }
  cout << endl;
#ifdef LOCAL
  auto c2 = chrono::high_resolution_clock::now();
  cerr << "Time Used:" << chrono::duration_cast<chrono::milliseconds>(c2 - c1).count() << "ms"
       << endl;
#endif
  return 0;
}