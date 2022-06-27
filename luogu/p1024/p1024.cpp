#include <chrono>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;
double a,b,c,d;
double x1, x2, x3;
double m1, m2;

double calc_formula(double x) { return a * pow(x, 3) + b * pow(x, 2) + c * x + d; }

int main(int argc, const char* argvp[]) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  auto c1 = chrono::high_resolution_clock::now();
#endif
  scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
  // 大力出奇迹
  for(double i=-100; i<=100; i+=0.001) {
    double j = i + 0.001;
    double y1 = calc_formula(i);
    double y2 = calc_formula(j);
    if(y1 >= 0 && y2 <= 0 || y1 <= 0 && y2 >= 0) {
      double x = (i+j)/2;
      printf("%.2lf ", x);
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