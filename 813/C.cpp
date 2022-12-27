#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
void dfs(int u, int f, int d, const vector<vector<int>> &e, vector<int> &dis) {
  dis[u] = d;
  for (auto v : e[u])
    if (v != f) dfs(v, u, d + 1, e, dis);
}
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  vector<vector<int>> e(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  vector<int> da(n + 1), db(n + 1);
  dfs(1, 1, 0, e, da);
  dfs(x, x, 0, e, db);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (da[i] > db[i]) ans = max(ans, da[i] * 2);
  printf("%d\n", ans);
  return 0;
}