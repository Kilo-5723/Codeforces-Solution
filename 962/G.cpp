#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct cplx {
  int x, y;
};
vector<pair<cplx, int>> solve(cplx a, cplx b, int x1, int y1, int x2, int y2) {
  bool flp = false;
  if (a.x == b.x) {
    swap(a.x, a.y);
    swap(b.x, b.y);
    swap(x1, y1);
    swap(x2, y2);
    flp = true;
  }
  if (a.y < y1 || a.y > y2) return {};
  int xa = a.x, xb = b.x, y = a.y;
  bool swp = false;
  if (xa > xb) {
    swap(xa, xb);
    swp = true;
  }
  vector<pair<cplx, int>> res;
  if (xa < x1 && xb > x1) res.push_back({{x1, y}, 0});
  if (xa < x2 && xb > x2) res.push_back({{x2, y}, 0});
  if (flp)
    for (auto &[cp, det] : res) swap(cp.x, cp.y);
  if (swp) reverse(res.begin(), res.end());
  return res;
}
int x1, y1, x2, y2;
int id(cplx a) {
  if (a.y == y1) return 1;
  if (a.x == x2) return 2;
  if (a.y == y2) return 3;
  if (a.x == x1) return 4;
  return -1;
}
bool cmp(cplx a, cplx b) {
  if (id(a) != id(b)) return id(a) < id(b);
  switch (id(a)) {
    case 1:
      return a.x < b.x;
    case 2:
      return a.y < b.y;
    case 3:
      return a.x > b.x;
    case 4:
      return a.y > b.y;
  }
  return false;
}
bool outside(const cplx &a, const vector<cplx> &poly) {
  bool res = true;
  for (int i = 1; i < poly.size(); i++) {
    auto p = poly[i - 1];
    auto q = poly[i];
    if (p.y == q.y) continue;
    if (p.y > q.y) swap(p.y, q.y);
    if (p.x < a.x && p.y < a.y && q.y > a.y) res ^= 1;
  }
  return res;
}
void dfs(int u, const vector<vector<int>> &e, vector<bool> &vis) {
  if (vis[u]) return;
  vis[u] = true;
  for (auto v : e[u]) dfs(v, e, vis);
}
int main() {
  scanf("%d%d%d%d", &x1, &y2, &x2, &y1);
  x1 = x1 * 3 + 1;
  x2 = x2 * 3 - 1;
  y1 = y1 * 3 + 1;
  y2 = y2 * 3 - 1;
  int n;
  scanf("%d", &n);
  vector<cplx> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].x *= 3;
    a[i].y *= 3;
  }
  a.push_back(a[0]);
  vector<pair<cplx, int>> crs;
  // for (auto [c, d] : crs) printf("(%lld,%lld):%d ", c.x, c.y, d);
  // puts("");
  for (int i = 0; i < n; i++) {
    auto tmp = solve(a[i], a[i + 1], x1, y1, x2, y2);
    crs.insert(crs.end(), tmp.begin(), tmp.end());
  }
  if (!crs.size()) {
    bool flg = true;
    if (a[0].x > x1 && a[0].x < x2 && a[0].y > y1 && a[0].y < y2)
      puts("1");
    else
      printf("%d\n", 1 - outside({x1, y1}, a));
    return 0;
  }
  n = crs.size();
  if (a[0].x > x1 && a[0].x < x2 && a[0].y > y1 && a[0].y < y2) {
    crs.push_back(crs[0]);
    crs.erase(crs.begin());
  }
  for (int i = 0; i < n; i++) crs[i].second = i >> 1;
  sort(crs.begin(), crs.end(), [&](pair<cplx, int> a, pair<cplx, int> b) {
    return cmp(a.first, b.first);
  });
  vector<vector<int>> e(n);
  vector<int> las(n / 2, -1);
  for (int i = 0; i < n; i++) {
    auto &j = las[crs[i].second];
    if (~j) {
      e[j].push_back((i + 1) % n);
      e[(i + 1) % n].push_back(j);
      e[j + 1].push_back(i);
      e[i].push_back(j + 1);
    } else {
      j = i;
    }
  }
  vector<bool> vis(n, false);
  int ans = 0;
  for (int i = outside({x1, y1}, a); i < n; i += 2)
    if (!vis[i]) {
      ans++;
      dfs(i, e, vis);
    }
  printf("%d\n", ans);
  return 0;
}