#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int inf = 1e9 + 1;
void dfs(int u, vector<int> &v, vector<int> &ls, vector<int> &rs, int l, int r,
         set<int> &st) {
  // cout << u << ' ' << v[u] << ' ' << l << ' ' << r << endl;
  if (!~u) return;
  if (v[u] > l && v[u] < r) st.insert(v[u]);
  dfs(ls[u], v, ls, rs, l, min(v[u], r), st);
  dfs(rs[u], v, ls, rs, max(l, v[u]), r, st);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n), d(n), ls(n), rs(n);
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d%d%d", &v[i], &l, &r);
    if (~l) d[--l]++;
    if (~r) d[--r]++;
    ls[i] = l;
    rs[i] = r;
  }
  set<int> ava;
  for (int i = 0; i < n; i++)
    if (!d[i]) dfs(i, v, ls, rs, -1e9, 1e9, ava);
  int ans = 0;
  for (auto a : v) ans += ava.count(a);
  printf("%d\n", n - ans);
  return 0;
}