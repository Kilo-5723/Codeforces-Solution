#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int lim = 1e6;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll inv(ll n) { return qpow(n, mod - 2); }
int main() {
  ll n, m;
  scanf("%lld%lld", &n, &m);
  ll ans = 0;
  for (ll i = 1; i <= m && n / i > lim; i++) ans += n % i % mod;
  ans %= mod;
  for (ll i = lim; i >= 0; i--) {
    ll l = n / (i + 1) + 1, r = i ? min(n / i, m) : m;
    if (l > m) break;
    ans += (r % mod - l % mod + 1) * (n % mod) % mod -
           (l % mod + r % mod) * (r % mod - l % mod + 1) % mod * inv(2) % mod *
               i % mod;
    ans %= mod;
  }
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}