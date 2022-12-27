#include <cstdio>
#include <iostream>
#include <tuple>
#include <set>
#include <vector>
using namespace std;
vector<set<int>> st;
pair<int, int> dfs(const vector<vector<int>>& e, const vector<int>& a, int u,
                   int f) {
  int res = 0;
  int cov = 0;
  bool flg = false;
  for (auto v : e[u])
    if (v != f) {
      auto [resv, covv] = dfs(e, a, v, u);
      res += resv;
      if (st[v].count(a[u] ^ covv)) flg = true;
      if (st[u].size() < st[v].size()) {
        swap(cov, covv);
        swap(st[u], st[v]);
      }
      for (auto v : st[v]) flg = flg || st[u].count(v ^ covv ^ cov ^ a[u]);
      for (auto v : st[v]) st[u].insert(v ^ covv ^ cov);
    }
  cov ^= a[u];
  st[u].insert(a[u] ^ cov);
  if (flg) {
    res++;
    st[u] = {};
  }
  return {res, cov};
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  vector<vector<int>> e(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  st.resize(n + 1);
  auto [res, cov] = dfs(e, a, 1, 1);
  printf("%d\n", res);
  return 0;
}