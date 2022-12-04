#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ll n, m, k, r, c;
  int ax, ay, bx, by;
  scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &r, &c);
  scanf("%d%d%d%d", &ax, &ay, &bx, &by);
  if (ax == bx && ay == by)
    printf("%lld\n", qpow(k, n * m));
  else
    printf("%lld\n", qpow(k, n * m - c * r));
  return 0;
}