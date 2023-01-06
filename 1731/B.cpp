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
ll inv(ll n) { return qpow(n, mod - 2); }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n;
    scanf("%lld", &n);
    ll ans = (n * (n + 1) % mod * (2 * n + 1) % mod * inv(3) % mod -
              n * n % mod + (n - 2) * (n - 1) % mod * inv(2) % mod + n - 1) %
             mod;
    ans = (ans % mod + mod) % mod;
    printf("%lld\n", ans * 2022 % mod);
  }
  return 0;
}