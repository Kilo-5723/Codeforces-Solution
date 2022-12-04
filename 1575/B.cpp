#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const double pi = 2 * acos(-1);
const double eps = 1e-8;
struct cplx {
  double x, y;
};
void push(vector<pair<double, int>> &arr, double l, double r) {
  while (l > 0) {
    l -= pi;
    r -= pi;
  }
  while (l < 0) {
    l += pi;
    r += pi;
  }
  if (r < pi) {
    arr.push_back({l, 1});
    arr.push_back({r, -1});
  } else {
    arr.push_back({0, 1});
    arr.push_back({r - pi, -1});
    arr.push_back({l, 1});
    arr.push_back({pi, -1});
  }
}
bool check(const vector<cplx> &a, int k, double r) {
  vector<pair<double, int>> arr;
  for (const auto &[x, y] : a) {
    double d = sqrt(x * x + y * y);
    if (d > 2 * r - eps) continue;
    auto ang = atan2(y, x), det = acos(d / 2 / r);
    push(arr, ang - det, ang + det);
  }
  sort(arr.begin(), arr.end());
  int t = 0;
  if (t >= k) return true;
  for (auto [x, d] : arr) {
    // printf("%lf %d\n",x,d);
    t += d;
    // cout<<t<<' '<<k<<endl;
    if (t >= k) return true;
  }
  return false;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<cplx> a;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (!x && !y)
      k--;
    else
      a.push_back({x + 0.0, y + 0.0});
  }
  double l = 0, r = 2e5;
  while (r - l > eps) {
    // cout << l << ' ' << r << endl;
    double m = (l + r) / 2;
    if (check(a, k, m))
      r = m;
    else
      l = m;
  }
  printf("%.6f\n", (l + r) / 2);
  return 0;
}