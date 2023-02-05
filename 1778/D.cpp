#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 5;
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
  vector<ll> inv(maxn);
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) inv[i] = -mod / i * inv[mod % i] % mod;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<pair<ll, ll>> a(n + 1);
    a[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
      auto [p, q] = a[i - 1];
      ll k = 1 - i * p % mod * inv[n] % mod;
      k = qpow(k, mod - 2);
      ll p2 = (n - i) * inv[n] % mod;
      ll q2 = 1 + i * q % mod * inv[n] % mod;
      a[i] = {p2 * k % mod, q2 * k % mod};
    }
    vector<ll> b(n + 1);
    b[n] = a[n].second;
    for (int i = n - 1; i; i--)
      b[i] = (a[i].first * b[i + 1] % mod + a[i].second) % mod;
    vector<char> s(n + 1), t(n + 1);
    scanf("%s", s.data());
    scanf("%s", t.data());
    int m = 0;
    for (int i = 0; i < n; i++) m += s[i] ^ t[i];
    printf("%lld\n", (b[m] % mod + mod) % mod);
  }
  return 0;
}