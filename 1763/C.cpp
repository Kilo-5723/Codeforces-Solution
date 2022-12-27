#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    if (n == 2) {
      if (a[0] > a[1]) swap(a[0], a[1]);
      printf("%lld\n", max(a[0] + a[1], (a[1] - a[0]) * 2));
      continue;
    }
    if (n == 3) {
      if (a[0] > a[2]) swap(a[0], a[2]);
      printf("%lld\n", max({a[0] + a[1] + a[2], a[2] * 3, (a[1] - a[0]) * 3}));
      continue;
    }
    ll ans = 0;
    for (auto v : a) ans = max(ans, v * n);
    printf("%lld\n", ans);
  }
  return 0;
}