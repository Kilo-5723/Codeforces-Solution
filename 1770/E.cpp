#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll qpow(ll a, ll b) {
  return b ? (b & 1 ? a : 1) * qpow(a * a % mod, b >> 1) % mod : 1;
}
ll inv(ll n) { return qpow(n, mod - 2); }
void dfs(int u, int f, int d, vector<vector<int>> &e, vector<int> &size,
         vector<int> &dep) {
  dep[u] = d;
  for (auto v : e[u])
    if (v != f) {
      dfs(v, u, d + 1, e, size, dep);
      size[u] += size[v];
    }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int cnt = 0;
  vector<int> a(k);
  for (int i = 0; i < k; i++) scanf("%d", &a[i]);
  vector<pair<int, int>> ed;
  vector e(n + 1, vector<int>());
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    ed.push_back({u, v});
    e[u].push_back(v);
    e[v].push_back(u);
  }
  vector<int> size(n + 1), dep(n + 1);
  for (auto v : a) size[v]++;
  dfs(1, 1, 0, e, size, dep);
  vector<ll> p(n + 1);
  for (auto v : a) p[v] = 1;
  ll ans = 0;
  ll inv2 = inv(2);
  for (auto [u, v] : ed) {
    if (dep[u] < dep[v]) swap(u, v);
    ll a = size[u], b = k - a;
    ll pa = p[u], pb = p[v];
    ans = (ans + ((pa * pb + (1 - pa) * (1 - pb)) % mod) * (a * b % mod)) % mod;
    ans = (ans + ((pa * (1 - pb)) % mod) *
                     ((a * b + (a - 1) * (b + 1)) % mod * inv2 % mod)) %
          mod;
    ans = (ans + (((1 - pa) * pb) % mod) *
                     ((a * b + (a + 1) * (b - 1)) % mod * inv2 % mod)) %
          mod;
    p[u] = p[v] = (pa + pb) * inv2 % mod;
  }
  ans = ans * inv(1ll * k * (k - 1) / 2 % mod) % mod;
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}