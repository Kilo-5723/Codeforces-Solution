// #define LOCAL

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5, cube = maxn >> 1;
vector<int> e[maxn];
int clk, m;
int fa[maxn], vis[maxn];
bool ring[maxn];
vector<int> g[maxn];
void search(int u, int f) {
  vis[u] = ++clk;
  fa[u] = f;
  for (auto v : e[u])
    if (v != f) {
      if (!vis[v]) {
        ring[u] = false;
        search(v, u);
        if (!ring[u]) {
          g[u].push_back(v);
          g[v].push_back(u);
        }
      } else {
        if (vis[v] < vis[u]) {
          for (int w = u; w != fa[v]; w = fa[w]) {
            ring[w] = true;
            g[m].push_back(w);
            g[w].push_back(m);
          }
          m++;
        }
      }
    }
}
void build(int n) {
  clk = 0;
  m = cube;
  fill(vis, vis + n + 1, 0);
  fill(g, g + n + 1, vector<int>{});
  search(1, -1);
  for (int i = 0; i <= n; i++) e[i] = g[i];
  for (int i = cube; i < m; i++) e[i] = g[i];
}
bool iscube(int u) { return u >= cube; }
struct res {
  char op;
  int a, b, c;
};
vector<res> ans;
void solve(int u, int f) {
  if (!iscube(u)) ans.push_back({'r', u, 1, 4});
  for (auto v : e[u])
    if (v != f) solve(v, u);
  if (iscube(u)) {
    int w = e[u].back();
    for (auto v : e[u]) {
      if (v != f) {
        ans.push_back({'r', v, 4, 3});
        ans.push_back({'j', w, v, 0});
      }
      ans.push_back({'c', w, w == f ? 4 : 2, v == f ? 4 : 3});
      ans.push_back({'r', w, 2, 1});
      ans.push_back({'r', v, 3, 2});
      w = v;
    }
  } else {
    for (auto v : e[u])
      if (v != f && !iscube(v)) {
        ans.push_back({'r', v, 4, 2});
        ans.push_back({'j', u, v, 0});
      }
    ans.push_back({'c', u, 4, 2});
    ans.push_back({'r', u, 2, 1});
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int k;
    scanf("%d", &k);
    for (int u = 0; k; k--) {
      int v;
      scanf("%d", &v);
      if (u) {
        e[u].push_back(v);
        e[v].push_back(u);
      }
      u = v;
    }
  }
  build(n);
  solve(1, 1);
  printf("%lu\n", ans.size());
  for (auto ins : ans) {
    if (ins.op == 'j')
      printf("%c %d %d\n", ins.op, ins.a, ins.b);
    else
      printf("%c %d %d %d\n", ins.op, ins.a, ins.b, ins.c);
  }
  return 0;
}