#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int maxl = 30;
struct LinBase {
  int a[maxl + 1];
  void insert(int n) {
    for (int i = maxl; i >= 0; i--)
      if (n >> i & 1)
        if (a[i]) {
          n ^= a[i];
        } else {
          a[i] = n;
          break;
        }
  }
  int max() {
    int res = 0;
    for (int i = maxl; i >= 0; i--) res = std::max(res, res ^ a[i]);
    return res;
  }
};
void operator+=(LinBase &a, LinBase b) {
  for (auto v : b.a)
    if (v) a.insert(v);
}
LinBase operator+(LinBase a, LinBase b) {
  a += b;
  return a;
}
void dfs1(int u, int f, const vector<int> &a, vector<LinBase> &arr,
          vector<vector<int>> &e) {
  arr[u].insert(a[u]);
  for (auto v : e[u])
    if (v != f) {
      dfs1(v, u, a, arr, e);
      arr[u] += arr[v];
    }
}
void dfs2(int u, int f, const vector<int> &a, vector<LinBase> &arr,
          vector<vector<int>> &e, const vector<vector<int>> &qon,
          vector<map<int, int>> &res) {
  auto resr = arr[u];
  auto &adj = e[u];
  int n = adj.size();
  vector<LinBase> pre(n + 1), suf(n + 1);
  pre[0].insert(a[u]);
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[adj[i]];
  for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + arr[adj[i]];
  arr[u] = pre[n];
  for (auto v : qon[u]) res[u][v] = arr[v].max();
  for (int i = 0; i < n; i++) {
    int v = adj[i];
    if (v == f) continue;
    arr[u] = pre[i] + suf[i + 1];
    dfs2(v, u, a, arr, e, qon, res);
  }
  arr[u] = resr;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    vector e(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    int q;
    scanf("%d", &q);
    vector<pair<int, int>> qry(q);
    vector qon(n + 1, vector<int>());
    vector<map<int, int>> ans(n + 1);
    for (auto &[r, v] : qry) {
      scanf("%d%d", &r, &v);
      qon[r].push_back(v);
    }
    vector<LinBase> arr(n + 1);
    dfs1(1, -1, a, arr, e);
    dfs2(1, -1, a, arr, e, qon, ans);
    for (auto &[r, v] : qry) printf("%d\n", ans[r][v]);
  }
  return 0;
}