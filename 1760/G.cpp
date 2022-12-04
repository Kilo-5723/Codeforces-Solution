#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct Edge {
  int v, w;
};
vector<vector<Edge>> e;
void dfs(int u, int t, int f, int val, vector<int> &arr) {
  if (u == t) return;
  arr.push_back(val);
  for (auto [v, w] : e[u])
    if (v != f) dfs(v, t, u, val ^ w, arr);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    e.assign(n + 1, {});
    for (int i = 1; i < n; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      e[u].push_back({v, w});
      e[v].push_back({u, w});
    }
    vector<int> va, vb;
    dfs(a, b, -1, 0, va);
    dfs(b, -1, -1, 0, vb);
    set<int> st;
    for (auto v : va) st.insert(v);
    vb.erase(vb.begin());
    bool flg = false;
    for (auto v : vb)
      if (st.count(v)) flg = true;
    puts(flg ? "YES" : "NO");
  }
  return 0;
}