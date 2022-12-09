#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
char s[1005][1005];
ll c[2];
int g[1005][1005], t;
pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, is[10005];
int vis[10005];
int pr[N];
int id(int x, int y) {
  if (!g[x][y])
    return is[++t] = {x, y}, g[x][y] = ++t;
  else
    return g[x][y];
}
int dfs(int x, int tg) {
  auto [X, Y] = is[x];
  if (vis[x] == tg) return 0;
  vis[x] = tg;
  for (auto [dx, dy] : dir) {
    int i = id(X + dx, Y + dy);
    if (pr[i] == 0 || dfs(pr[i], tg)) return pr[i] = x, 1;
  }
}
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
      if (s[i][j] == '.') c[(i + j) & 1]++;
    }
  long long ans = 0;
  ans += c[1] * (c[1] - 1) / 2 + c[0] * (c[0] - 1) / 2;
  if (ans >= 1000000) {
    cout << 1000000 << '\n';
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.') dfs(id(i, j), id(i, j));
  for (int i = 1; i <= 10005; i++)
    if (pr[i]) pr[pr[i]] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.' && (i + j) % 2 == 1) {
        queue<int> q;
      }
}