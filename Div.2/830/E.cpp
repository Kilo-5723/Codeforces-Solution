#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int maxn = 5e4 + 5, maxm = 1 << 17;
void push(unordered_map<int, int> &a, const pair<int, int> &b) {
  if (a.count(b.first))
    a[b.first] = min(a[b.first], b.second);
  else
    a[b.first] = b.second;
}
unordered_map<int, int> operator+(unordered_map<int, int> a,
                                  const unordered_map<int, int> &b) {
  for (auto pr : b) push(a, pr);
  return a;
}
ll calc(unordered_map<int, int> &v, int m) {
  ll ans = inf;
  for (int i = 1; i * i <= m; i++)
    if (!(m % i)) {
      if (v.count(i)) ans = min(ans, 1LL * m / i * v[i]);
      if (v.count(m / i)) ans = min(ans, 1LL * v[m / i] * i);
    }
  return ans;
}
int l[maxm], r[maxm];
unordered_map<int, int> arr[maxm];
ll mnm[maxm];
int tag[maxm];
int a[maxn], b[maxn];
inline int ls(int u) { return u << 1; }
inline int rs(int u) { return u << 1 | 1; }
void addtag(int u, int _tag) {
  tag[u] = _tag;
  mnm[u] = calc(arr[u], _tag);
}
void pushtag(int u) {
  if (!~tag[u]) return;
  addtag(ls(u), tag[u]);
  addtag(rs(u), tag[u]);
  tag[u] = -1;
}
void update(int u) { mnm[u] = min(mnm[ls(u)], mnm[rs(u)]); }
void build(int u, int _l, int _r) {
  l[u] = _l;
  r[u] = _r;
  arr[u] = {};
  mnm[u] = inf;
  tag[u] = -1;
  if (_l == _r) {
    int aa = a[_l], bb = b[_l];
    for (int i = 1; i * i <= bb; i++)
      if (!(bb % i)) {
        arr[u][i] = bb / i;
        arr[u][bb / i] = i;
      }
    mnm[u] = calc(arr[u], aa);
    return;
  }
  int _m = (_l + _r) / 2;
  build(ls(u), _l, _m);
  build(rs(u), _m + 1, _r);
  arr[u] = arr[ls(u)] + arr[rs(u)];
  update(u);
}
void change(int u, int _l, int _r, int x) {
  if (l[u] > _r || r[u] < _l) return;
  if (l[u] >= _l && r[u] <= _r) {
    addtag(u, x);
    return;
  }
  pushtag(u);
  change(ls(u), _l, _r, x);
  change(rs(u), _l, _r, x);
  update(u);
}
ll query(int u, int _l, int _r) {
  if (l[u] > _r || r[u] < _l) return inf;
  if (l[u] >= _l && r[u] <= _r) return mnm[u];
  pushtag(u);
  return min(query(ls(u), _l, _r), query(rs(u), _l, _r));
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  build(1, 0, n - 1);
  // puts("333");
  while (q--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    l--;
    r--;
    if (op == 1) {
      int x;
      scanf("%d", &x);
      change(1, l, r, x);
    } else {
      printf("%lld\n", query(1, l, r));
    }
  }
  return 0;
}