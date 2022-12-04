#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
vector<vector<int>> e;
vector<vector<int>> dep;
int d;
int dfs(int u, int f) {
  int res = 0;
  for (auto v : e[u])
    if (v != f) {
      res += dfs(v, u);
      for (auto b : {0, 1}) dep[u][b] = max(dep[u][b], dep[v][b]+1);
    }
  for (auto b : {0, 1})
    if (dep[u][b] >= 0 || dep[u][!b] >= d) res+=2;
  // printf("%d %d %d\n", u,dep[u][0], dep[u][1]);
  return res;
}
int main() {
  int n;
  scanf("%d%d", &n, &d);
  e.assign(n + 1, {});
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dep.assign(n + 1, vector<int>(2, -inf));
  int k;
  scanf("%d", &k);
  while (k--) {
    int u;
    scanf("%d", &u);
    dep[u][0] = 0;
  }
  scanf("%d", &k);
  while (k--) {
    int u;
    scanf("%d", &u);
    dep[u][1] = 0;
  }
  printf("%d\n", dfs(1, 1)-4);
  return 0;
}