#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
struct cplx {
  ll x, y;
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
  int xa = a.x, xb = b.x;
  bool swp = false;
  if (xa > xb) {
    swap(xa, xb);
    swp = true;
  }
  vector<pair<cplx, int>> res;
  if (xa < x1 && xb > x1) res.push_back({{x1, a.y}, 0});
  if (xa < x2 && xb > x2) res.push_back({{x2, b.y}, 0});
  if (flp)
    for (auto &[cp, det] : res) swap(cp.x, cp.y);
  if (swp && res.size() == 2) swap(res[0], res[1]);
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
  x1 = x1 * 2 + 1;
  x2 = x2 * 2 - 1;
  y1 = y1 * 2 + 1;
  y2 = y2 * 2 - 1;
  int n;
  scanf("%d", &n);
  vector<cplx> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &a[i].x, &a[i].y);
    a[i].x *= 2;
    a[i].y *= 2;
  }
  a.push_back(a[0]);
  vector<pair<cplx, int>> crs;
  // for (auto [c, d] : crs) printf("(%lld,%lld):%d ", c.x, c.y, d);
  // puts("");
  for (int i = 0; i < n; i++) {
    auto tmp = solve(a[i], a[i + 1], x1, y1, x2, y2);
    crs.insert(crs.end(), tmp.begin(), tmp.end());
  }
  // for (auto [c, d] : crs) printf("(%lld,%lld):%d ", c.x, c.y, d);
  // puts("");
  if (!crs.size()) {
    bool flg = true;
    for (auto [x, y] : a)
      if (x > x1 && x < x2 && y > y1 && y < y2) {
        puts("1");
        return 0;
      }
    printf("%d\n", 1 - outside({x1, y1}, a));
    return 0;
  }
  if (a[0].x > x1 && a[0].x < x2 && a[0].y > y1 && a[0].y < y2) {
    crs.push_back(crs[0]);
    crs.erase(crs.begin());
  }
  for (int i = 0; i < crs.size(); i++) {
    crs[i].second = i >> 1;
  }
  // for (auto [c, d] : crs) printf("(%lld,%lld):%d ", c.x, c.y, d);
  // puts("");
  sort(crs.begin(), crs.end(), [&](pair<cplx, int> a, pair<cplx, int> b) {
    auto [ca, da] = a;
    auto [cb, db] = b;
    if (id(ca) != id(cb)) return id(ca) < id(cb);
    switch (id(ca)) {
      case 1:
        return ca.x < cb.x;
      case 2:
        return ca.y < cb.y;
      case 3:
        return ca.x > cb.x;
      case 4:
        return ca.y > cb.y;
    }
    return false;
  });
  // for (auto [c, d] : crs) printf("(%lld,%lld):%d ", c.x, c.y, d);
  // puts("");
  n = crs.size();
  int m = n / 2;
  vector<vector<int>> e(n);
  vector<int> las(m, -1);
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
  vector<bool> vis(n);
  int ans = 0;
  // cout << outside({x1, y1}, a) << endl;
  for (int i = outside({x1, y1}, a); i < n; i += 2)
    if (!vis[i]) {
      ans++;
      dfs(i, e, vis);
    }
  printf("%d\n", ans);
  return 0;
}