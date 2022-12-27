#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
vector<ll> fact, ifac;
ll c(int n, int m) { return fact[n] * ifac[m] % mod * ifac[n - m] % mod; }
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
ll tcnt(ll n) {
  if (n == 1) return 1;
  return qpow(n, n - 2);
}
int main() {
  int n;
  scanf("%d", &n);
  if (n & 1) {
    puts("0");
    return 0;
  }
  fact.resize(n + 1);
  ifac.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
  ifac[n] = inv(fact[n]);
  for (int i = n; i >= 1; i--) ifac[i - 1] = ifac[i] * i % mod;
  ll ans = 0;
  for (int i = 1; i < n; i++)
    ans += (i & 1 ? -1 : 1) * c(n - 2, i - 1) % mod * qpow(i, i - 1) % mod *
           qpow(n - i, n - i - 1) % mod;
  printf("%lld\n", (ans % mod % mod + mod) % mod);
  return 0;
}