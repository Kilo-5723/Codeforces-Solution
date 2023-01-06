#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
bool check(const vector<int> &a, int m) {
  ll sum = 0;
  for (auto v : a)
    if (v < m)
      sum += (m - v) / 2;
    else
      sum -= v - m;
  return sum >= 0;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n, 0);
    for (int i = 0; i < m; i++) {
      int t;
      scanf("%d", &t);
      a[t - 1]++;
    }
    sort(a.begin(), a.end());
    int l = a[0] - 1, r = a.back();
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (check(a, m))
        r = m;
      else
        l = m;
    }
    printf("%d\n", r);
  }
  return 0;
}