#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 2000;
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
vector split(maxn, vector<ll>(maxn, -1));
ll prob_split(ll a, ll b) {
  if (a == 0 && b == 0) return 1;
  if (a < 0 || b < 0) return 0;
  if (~split[a][b]) return split[a][b];
  ll res = 0;
  if (!a) res += 1;
  res += prob_split(a - 1, b) * (2 * a - 1) % mod;
  res += prob_split(a, b - 1) * (2 * b - 1) % mod;
  return split[a][b] = res % mod * inv(2 * a + 2 * b + 1) % mod;
}
vector dp(maxn, vector<ll>(maxn, -1));
ll dfs(ll n, ll k, ll p) {
  if (k < 0) return 0;
  if (!n) return 1;
  if (~dp[n][k]) return dp[n][k];
  ll res = 0;
  for (int i = 0; i <= n - 1; i++) {
    auto pp = prob_split(i, n - 1 - i);
    ll tmp = (p * dfs(i, k + 1, p) + (1 - p) * dfs(i, k - 1, p)) % mod *
             dfs(n - 1 - i, k, p) % mod;
    res = res + (tmp * pp) % mod;
  }
  return dp[n][k] = res % mod;
}
int main() {
  int n;
  ll q;
  scanf("%d%lld", &n, &q);
  auto ans = dfs(n, 0, q * inv(10000) % mod);
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}