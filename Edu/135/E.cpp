#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
ll a[maxn], b[maxn];
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll g = exgcd(b, a % b, y, x);
  y -= a / b * x;
  printf("%lld %lld %lld %lld\n", a, x, b, y);
  return g;
}
int main() {
  ll x, y;
  exgcd(194, 251, x, y);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld%lld", &a[i], &b[i]);
    int m;
    scanf("%d", &m);
    while (m--) {
      ll p, q;
      scanf("%lld%lld", &p, &q);
      ll x, y, g;
      g = exgcd(p, q, x, y);
      if (n % g) {
        puts("-1");
        continue;
      }
      x *= n / g;
      y *= n / g;
    }
  }
  return 0;
}