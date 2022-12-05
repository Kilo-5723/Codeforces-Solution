#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct edge {
  int u, v;
};
vector<edge> ed;
vector<vector<int>> e, rc;
vector<set<int>> dcc;
vector<int> dfn, low;
int dfc, cnt;
vector<int> stk;
void dfs(int u) {
  low[u] = dfn[u] = ++dfc;
  stk.push_back(u);
  for (int v : e[u]) {
    if (!dfn[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (low[v] == dfn[u]) {
        ++cnt;
        rc.push_back({});
        int k;
        do {
          k = stk.back();
          rc[cnt].push_back(k);
          rc[k].push_back(cnt);
          stk.pop_back();
        } while (k != v);
        rc[cnt].push_back(u);
        rc[u].push_back(cnt);
      }
    } else
      low[u] = min(low[u], dfn[v]);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  e.resize(n + 1);
  rc.resize(n + 1);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
    ed.push_back({u, v});
  }
  dfn.resize(n + 1);
  low.resize(n + 1);
  dfc = 0;
  cnt = n;
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) {
      stk.clear();
      dfs(i);
    }
  vector<set<int>> st(cnt - n);
  for (int i = n + 1; i <= cnt; i++)
    for (auto v : rc[i]) {
      st[i - n - 1].insert(v);
    }
  vector<vector<int>> edg(cnt - n);
  for (int i = 0; i < ed.size(); i++) {
    auto [u, v] = ed[i];
    if (rc[u].size() > rc[v].size()) swap(u, v);
    for (auto k : rc[u])
      if (st[k - n - 1].count(v)) edg[k - n - 1].push_back(i);
  }
  vector<int> ans;
  for (int i = 0; i < cnt - n; i++) {
    if (st[i].size() == edg[i].size()) {
      for (auto v : edg[i]) ans.push_back(v);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%lu\n", ans.size());
  for (auto v : ans) printf("%d ", v + 1);
  puts("");
  return 0;
}