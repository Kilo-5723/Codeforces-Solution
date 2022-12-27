#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
ll f(ll m, ll n) {
  return min(m * (m - 1) / 2, n - m) + n - m;
  // if (1ll * m * (m - 1) / 2 > n - m) return -inf - m;
  // return m
}
int main() {
  // cout << lim << endl;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n;
    scanf("%lld", &n);
    ll l = 1, r = n;
    while (r - l > 20) {
      ll m1 = (l + r) / 2, m2 = m1 + 1;
      if (f(m1, n) > f(m2, n))
        r = m2;
      else
        l = m1;
    }
    ll ans = -inf;
    for (ll i = l; i <= r; i++) ans = max(ans, f(i, n));
    printf("%lld\n", ans);
  }
  return 0;
}