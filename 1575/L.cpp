#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6 + 5;
int l[maxn], r[maxn], v[maxn];
int ls(int u) { return u << 1; }
int rs(int u) { return u << 1 | 1; }
void build(int u, int _l, int _r) {
  l[u] = _l;
  r[u] = _r;
  v[u] = 0;
  if (_l == _r) return;
  int _m = _l + (_r - _l) / 2;
  build(ls(u), _l, _m);
  build(rs(u), _m + 1, _r);
}
int query(int u, int _l, int _r) {
  if (l[u] > _r || r[u] < _l) return 0;
  if (l[u] >= _l && r[u] <= _r) return v[u];
  return max(query(ls(u), _l, _r), query(rs(u), _l, _r));
}
void modify(int u, int _p, int _v) {
  if (l[u] > _p || r[u] < _p) return;
  if (l[u] >= _p && r[u] <= _p) {
    v[u] = _v;
    return;
  }
  modify(ls(u), _p, _v);
  modify(rs(u), _p, _v);
  v[u] = max(v[ls(u)], v[rs(u)]);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = i + 1 - a[i];
  }
  build(1, 0, n);
  vector<int> ord;
  for (int i = 0; i < n; i++)
    if (b[i] >= 0) ord.push_back(i);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    if (a[i] != a[j]) return a[i] < a[j];
    return i > j;
  });
  for (auto i : ord) modify(1, b[i], query(1, 0, b[i]) + 1);
  printf("%d\n", query(1, 0, n));
  return 0;
}