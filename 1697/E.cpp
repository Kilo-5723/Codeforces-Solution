#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
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
struct cplx {
  int x, y;
};
cplx operator-(const cplx &a, const cplx &b) { return {a.x - b.x, a.y - b.y}; }
int abs(const cplx &a) { return abs(a.x) + abs(a.y); }
void dfs(int u, int d, int n, const vector<cplx> &a, vector<bool> &vis,
         vector<int> &arr) {
  if (vis[u]) return;
  vis[u] = true;
  for (int v = 0; v < n; v++)
    if (!vis[v] && abs(a[v] - a[u]) == d) dfs(v, d, n, a, vis, arr);
  arr.push_back(u);
}
vector<ll> fact, ifac;
ll memdp(int p, int n, int m, const vector<int> &a, vector<vector<ll>> &dp) {
  if (~dp[p][n]) return dp[p][n];
  if (p == a.size()) return dp[p][n] = fact[n] * ifac[n - m] % mod;
  ll res =
      fact[n] * ifac[n - a[p]] % mod * memdp(p + 1, n - a[p], m, a, dp) % mod;
  res = (res + n * memdp(p + 1, n - 1, m, a, dp)) % mod;
  return dp[p][n] = res % mod;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<cplx> a(n);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  vector<bool> vis(n);
  vector<int> arr;
  vector<pair<int, int>> que;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) que.push_back({i, j});
  sort(que.begin(), que.end(),
       [&](const pair<int, int> &p1, const pair<int, int> &p2) {
         auto [i1, j1] = p1;
         auto [i2, j2] = p2;
         return abs(a[i1] - a[j1]) < abs(a[i2] - a[j2]);
       });
  vector<int> s;
  int las = -1;
  for (auto [i, j] : que) {
    vector<int> arr;
    auto d = abs(a[i] - a[j]);
    if (d != las) vis.assign(n, false);
    las = d;
    dfs(i, abs(a[i] - a[j]), n, a, vis, arr);
    bool flg = true;
    for (auto u : arr)
      for (auto v : arr)
        if (u != v && abs(a[u] - a[v]) != d) flg = false;
    for (auto u : arr)
      for (int v = 0; v < n; v++)
        if (u != v && abs(a[v] - a[u]) < d) flg = false;
    if (flg && arr.size()) s.push_back(arr.size());
  }
  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
  ifac.resize(n + 1);
  ifac.back() = inv(fact.back());
  for (int i = n; i >= 1; i--) ifac[i - 1] = ifac[i] * i % mod;
  int m = n;
  for (auto v : s) m -= v;
  vector dp(n + 1, vector<ll>(n + 1, -1));
  printf("%lld\n", memdp(0, n, m, s, dp));
  return 0;
}