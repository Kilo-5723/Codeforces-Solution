#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 2e4;
char s[buff];
void findf(int u, int f, int r, const vector<vector<int>> &e,
           vector<vector<int>> &d) {
  d[u][r] = f;
  for (auto v : e[u])
    if (v != f) findf(v, u, r, e, d);
}
int solve(int u, int v, const vector<int> &a, const vector<vector<int>> &e,
          vector<vector<int>> &d, vector<vector<int>> &dp) {
  if (u > v) swap(u, v);
  if (~dp[u][v]) return dp[u][v];
  int res = 0;
  if (a[u] == a[v]) {
    for (auto p : e[u])
      if (p != d[u][v])
        for (auto q : e[v])
          if (q != d[v][u]) res = max(res, solve(p, q, a, e, d, dp));
    return dp[u][v] = res + 2;
  }
  for (auto w : e[u])
    if (w != d[u][v]) res = max(res, solve(w, v, a, e, d, dp));
  for (auto w : e[v])
    if (w != d[v][u]) res = max(res, solve(u, w, a, e, d, dp));
  return dp[u][v] = res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) a[i + 1] = s[i];
    vector<vector<int>> e(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));
    for (int u = 1; u <= n; u++)
      for (auto v : e[u]) findf(v, u, u, e, d);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = 1;
    for (int u = 1; u <= n; u++) {
      for (auto v : e[u])
        for (auto w : e[u])
          if (v != w) ans = max(ans, solve(v, w, a, e, d, dp) + 1);
      for (auto v : e[u]) ans = max(ans, solve(u, v, a, e, d, dp));
    }
    printf("%d\n", ans);
  }
  return 0;
}