#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const vector<pair<int, int>> d{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int buff = 2000;
char s[buff];
bool legal(int x, int y, const vector<vector<int>> &a) {
  if (x < 0 || x >= a.size()) return false;
  if (y < 0 || y >= a[0].size()) return false;
  return ~a[x][y];
}
int ff(int u, vector<int> &f, vector<int> &c) {
  return f[u] == u ? u : f[u] = ff(f[u], f, c);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector a(n, vector<int>(m));
  int k = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) a[i][j] = s[j] == '*' ? -1 : ++k;
  }
  vector<int> f(k + 1), c(k + 1);
  for (int i = 1; i <= k; i++) {
    f[i] = i;
    c[i] = 1;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (auto [x, y] : d)
        if (~a[i][j] && legal(i + x, j + y, a)) {
          int u = ff(a[i][j], f, c), v = ff(a[i + x][j + y], f, c);
          if (u != v) {
            f[u] = v;
            c[v] += c[u];
          }
        }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (~a[i][j]) {
        putchar('.');
      } else {
        set<int> st;
        int ans = 1;
        for (auto [x, y] : d)
          if (legal(i + x, j + y, a)) {
            int u = ff(a[i + x][j + y], f, c);
            if (!st.count(u)) {
              ans += c[u];
              st.insert(u);
            }
          }
        printf("%d", ans % 10);
      }
    puts("");
  }
  return 0;
}