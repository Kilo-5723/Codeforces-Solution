#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
vector<ll> fact, ifac;
vector<ll> pow2, pow3;
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
void init(int n) {
  fact.resize(n);
  fact[0] = 1;
  for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % mod;
  ifac.resize(n);
  ifac[n - 1] = inv(fact[n - 1]);
  for (int i = n - 1; i; i--) ifac[i - 1] = ifac[i] * i % mod;
  pow2.resize(n);
  pow2[0] = 1;
  for (int i = 1; i < n; i++) pow2[i] = pow2[i - 1] * 2 % mod;
  pow3.resize(n);
  pow3[0] = 1;
  for (int i = 1; i < n; i++) pow3[i] = pow3[i - 1] * 3 % mod;
}
ll C(int n, int m) {
  if (n < m) return 0;
  return fact[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int cnt1(int n) { return n ? cnt1(n >> 1) + (n & 1) : 0; }
ll calc(int n, int k, int m) {
  if (m == 1) return n == k;
  int base0 = m / 2, base1 = m - base0;
  int extr0 = n - k - base0, extr1 = k - base1;
  return C(extr0 + base0 - 1, base0 - 1) * C(extr1 + base1 - 1, base1 - 1) %
         mod;
}
ll solve2(int n, int k) {
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (calc(n, k, i) + 3 * calc(n, n - k, i)) % mod * pow3[n - i] % mod;
  }
  return ans % mod;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  init(2 * n + 10);
  printf("%lld\n", solve2(n, k));
  return 0;
}