#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 4e5;
char s[buff];
struct Dsu {
  vector<int> f, c;
  void init(int n) {
    f.resize(n + 1);
    c.assign(n + 1, 1);
    for (int i = 0; i <= n; i++) f[i] = i;
  }
  int ff(int u) { return f[u] == u ? u : f[u] = ff(f[u]); }
  void conn(int u, int v) {
    u = ff(u);
    v = ff(v);
    if (u != v) {
      f[u] = v;
      c[v] += c[u];
    }
  }
  int size(int u) { return c[ff(u)]; }
};
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector id(n + 1, vector<int>(2, 0));
    int k = 0;
    for (auto &arr : id)
      for (auto &v : arr) v = k++;
    Dsu ds;
    ds.init(k);
    scanf("%s", s);
    for (int i = 0; s[i]; i++)
      ds.conn(id[i][s[i] == 'L'], id[i + 1][s[i] == 'R']);
    for (int i = 0; i <= n; i++) printf("%d ", ds.size(id[i][0]));
    puts("");
  }
  return 0;
}