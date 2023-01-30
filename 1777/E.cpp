#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e9 + 6;
struct Edge {
  int u, v;
  ll w;
};
int n;
vector<vector<int>> e, r;
vector<int> col;
vector<bool> vis;
vector<int> seq;
void dfs1(int u) {
  if (vis[u]) return;
  vis[u] = true;
  for (auto v : e[u]) dfs1(v);
  seq.push_back(u);
}
void dfs2(int u, int c) {
  if (vis[u]) return;
  vis[u] = true;
  col[u] = c;
  for (auto v : r[u]) dfs2(v, c);
}
int get_scc() {
  seq.clear();
  vis.assign(n + 1, false);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs1(i);
  reverse(seq.begin(), seq.end());
  vis.assign(n + 1, false);
  n = 0;
  for (auto u : seq) dfs2(u, ++n);
  return n;
}
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  for (auto v : e[u]) dfs(v);
}
bool check(ll ww, int n, vector<Edge> &edge) {
  for (auto &arr : e) arr.clear();
  for (auto &arr : r) arr.clear();
  for (auto [u, v, w] : edge)
    if (w <= ww) {
      e[u].push_back(v);
      r[v].push_back(u);
    }
  col.assign(n + 1, 0);
  int k = get_scc();
  for (int i = 1; i <= n; i++)
    if (col[i] == 1) {
      vis.assign(n + 1, false);
      dfs(i);
      for (int i = 1; i <= n; i++)
        if (!vis[i]) return false;
      return true;
    }
  return false;
}
int main() {
  int tt;
  scanf("%d", &tt);
  vector<Edge> edge;
  while (tt--) {
    int m;
    scanf("%d%d", &n, &m);
    edge.clear();
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      edge.push_back({u, v, 0});
      edge.push_back({v, u, w});
    }
    e.assign(n + 1, {});
    r.assign(n + 1, {});
    ll l = -1, r = inf;
    while (r - l > 1) {
      ll m = (l + r) / 2;
      if (check(m, n, edge))
        r = m;
      else
        l = m;
    }
    printf("%lld\n", r < inf ? r : -1);
  }
  return 0;
}