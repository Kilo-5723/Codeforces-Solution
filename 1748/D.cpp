#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
typedef __int128 li;
const ll thrs = 1e18;
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll res = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    a |= b;
    int cnt = 0;
    bool flg = false;
    while (!(d & 1)) {
      if (a & 1) flg = true;
      a >>= 1;
      d >>= 1;
      cnt++;
    }
    if (flg) {
      puts("-1");
      continue;
    }
    ll x, y;
    exgcd(1 << 30, d, x, y);
    x = (x % d + d) % d;
    ll res = ((x * -a) % d + d) % d;
    res <<= 30;
    res |= a;
    res <<= cnt;
    printf("%lld\n", res);
  }
  return 0;
}