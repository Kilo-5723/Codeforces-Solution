#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll mod;
vector<ll> fact, ifac;
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
ll comb(ll n, ll m) { return fact[n] * ifac[m] % mod * ifac[n - m] % mod; }
void init(int n) {
  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
  ifac.resize(n + 1);
  ifac.back() = inv(fact.back());
  for (int i = n; i >= 1; i--) ifac[i - 1] = ifac[i] * i % mod;
}

int main() {
  int n;
  scanf("%d%lld", &n, &mod);
  init(3 * n);
  ll ans = -1;
  ll case1 = (fact[2 * n] * 2 - fact[n]) % mod;
  ans = (ans - case1) % mod;
  ll case2 = comb(2 * n, n) * fact[n] % mod * fact[2 * n] * 2 % mod;
  for (int i = 0; i <= n; i++)
    case2 = (case2 - qpow(comb(n, i), 3) * fact[n] % mod * fact[i] % mod *
                         fact[2 * n - i] % mod) %
            mod;
  ans = (ans + case2 * 2) % mod;
  ans = (ans + (fact[3 * n] - case2) * 3) % mod;
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}