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
  if (a.y >= y2 || a.y <= y1) return {};
  int xa = a.x, xb = b.x;
  if (xa > xb) swap(xa, xb);
  vector<pair<cplx, int>> res;
  if (xa <= x1 && xb >= x2) res = {{{x1, a.y}, 0}, {{x2, b.y}, 0}};
  if (xa <= x1 && xb > x1) res = {{{x1, a.y}, 0}};
  if (xa < x2 && xb >= x2) res = {{{x2, b.y}, 0}};
  if (flp)
    for (auto &[cp, det] : res) swap(cp.x, cp.y);
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
bool in(cplx a, cplx b, cplx c) {
  if (b.x > c.x) swap(b.x, c.x);
  if (b.y > c.y) swap(b.y, c.y);
  return a.x >= b.x && a.x <= c.x && a.y >= b.y && a.y < c.y;
}
bool outside(const cplx &a, const vector<cplx> &poly) {
  bool res = false;
  for (int i = 1; i < poly.size(); i++) {
    auto p = poly[i - 1];
    auto q = poly[i];
    if (in(a, p, q)) return false;
    if (p.y == q.y) continue;
    if (p.y > q.y) swap(p.y, q.y);
    if (p.y >= a.y || q.y < a.y) res ^= 1;
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
  int n;
  scanf("%d", &n);
  vector<cplx> a(n);
  for (int i = 0; i < n; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
  a.push_back(a[0]);
  vector<pair<cplx, int>> crs;
  for (int i = 0; i < n; i++) {
    auto tmp = solve(a[i], a[i + 1], x1, y1, x2, y2);
    crs.insert(crs.end(), tmp.begin(), tmp.end());
  }
  if (a[0].x > x1 && a[0].x < x2 && a[0].y > y1 && a[0].y < y2) {
    if (!crs.size()) {
      puts("1");
      return 0;
    }
    crs.push_back(crs[0]);
    crs.erase(crs.begin());
  }
  for (int i = 0; i < crs.size(); i++) {
    crs[i].second = i >> 1;
  }
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
  n = crs.size();
  int m = n / 2;
  int ans = 0;
  vector<vector<int>> e(n);
  vector<int> las(m, -1);
  for (int i = 0; i < n; i++)
    if (~las[crs[i].second]) {
      int j = las[crs[i].second];
      e[j].push_back((i + 1) % n);
      e[(i + 1) % n].push_back(j);
      e[j + 1].push_back(i);
      e[i].push_back(j + 1);
    }
  vector<bool> vis(n);
  for (int i = outside({x1, y1}, a); i < n; i += 2)
    if (!vis[i]) {
      ans++;
      dfs(i, e, vis);
    }
  printf("%d\n", ans);
  return 0;
}