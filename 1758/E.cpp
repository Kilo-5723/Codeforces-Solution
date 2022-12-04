#include <cstdio>
#include <iostream>
#include <vector>
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
int h;
bool dfs(int u, int k, vector<int> &a, vector<vector<pair<int, int>>> &e) {
  if (~a[u]) return a[u] == k;
  a[u] = k;
  for (auto [v, w] : e[u])
    if (!dfs(v, (w - k + h) % h, a, e)) return false;
  return true;
}
ll solve(vector<vector<pair<int, int>>> &e) {
  int n = e.size();
  vector<int> a(n, -1);
  int res = 0;
  for (int i = 0; i < n; i++)
    if (!~a[i]) {
      res++;
      if (!dfs(i, 0, a, e)) return 0;
    }
  return qpow(h, res - 1);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d%d", &n, &m, &h);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    vector<vector<pair<int, int>>> e(n + m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (~a[i][j]) {
          e[i].push_back({j + n, a[i][j]});
          e[j + n].push_back({i, a[i][j]});
        }
    printf("%lld\n", solve(e));
  }
  return 0;
}
