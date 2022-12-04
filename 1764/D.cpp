#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> fact, ifac, pow2;
ll mod;
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
ll C(int n, int m) { return fact[n] * ifac[m] % mod * ifac[n - m] % mod; }
int main() {
  int n;
  scanf("%d%lld", &n, &mod);
  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
  ifac.resize(n + 1);
  ifac[n] = inv(fact[n]);
  for (int i = n; i >= 1; i--) ifac[i - 1] = ifac[i] * i % mod;
  pow2.resize(n + 1);
  pow2[0] = 1;
  for (int i = 1; i <= n; i++) pow2[i] = pow2[i - 1] * i % mod;
  ll ans = (n & 1) ? 0 : fact[n - 2];
  for (int i = 1; i * 2 < n; i++)
    for (int j = 0; j < i; j++)
      ans += (i + !(n & 1)) * fact[n - 3 - j] % mod * C(i - 1, j) % mod;
  printf("%lld\n", ans % mod * n % mod);
  return 0;
}