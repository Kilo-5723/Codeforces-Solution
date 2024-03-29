#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e9;
const int maxn = 5e4 + 5, blk = 100, maxm = 1 << 17;
struct dvs {
  vector<int> a;
  bool flg;
  dvs() { flg = false; }
};
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
// void push(dvs &a, const pair<int, int> &b) {
//   if (a.flg) {
//     a.a[b.first] = b.second;
//   } else {
//     a.a.push_back(b.first);
//     if (a.a.size() > blk) {
//       a.flg = true;
//       vector<int> c(maxn, inf);
//       for (auto v : a.a)
//         for (int i = 1; i * i <= v; i++)
//           if (!(v % i)) {
//             c[i] = min(c[i], v / i);
//             c[v / i] = min(c[v / i], i);
//           }
//       swap(a.a, c);
//     }
//   }
// }
void push(dvs &a, int b) {
  if (a.flg) {
    for (int i = 1; i * i <= b; i++)
      if (!(b % i)) {
        a.a[i] = min(a.a[i], b / i);
        a.a[b / i] = min(a.a[b / i], i);
      }
  } else {
    a.a.push_back(b);
    if (a.a.size() > blk) {
      a.flg = true;
      vector<int> c(maxn, inf);
      for (auto v : a.a)
        for (int i = 1; i * i <= v; i++) {
          c[i] = min(c[i], v / i);
          c[v / i] = min(c[v / i], i);
        }
      swap(a.a, c);
    }
  }
}
dvs operator+(dvs a, dvs b) {
  if (b.flg) swap(a, b);
  if (!b.flg)
    for (auto v : b.a) push(a, v);
  else
    for (int i = 0; i < maxn; i++) a.a[i] = min(a.a[i], b.a[i]);
  return a;
}
ll calc(dvs &a, int m) {
  ll ans = inf * inf;
  if (a.flg) {
    for (int i = 1; i * i <= m; i++)
      if (!(m % i)) {
        ans = min(ans, 1LL * m / i * a.a[i]);
        ans = min(ans, 1LL * a.a[m / i] * i);
      }
  } else {
    for (auto v : a.a) {
      int g = gcd(v, m);
      ans = min(ans, 1LL * v * m / g / g);
    }
  }
  return ans;
}
int l[maxm], r[maxm];
dvs val[maxm];
ll mnm[maxm];
int tag[maxm];
int a[maxn], b[maxn];
inline int ls(int u) { return u << 1; }
inline int rs(int u) { return u << 1 | 1; }
void addtag(int u, int _tag) {
  tag[u] = _tag;
  mnm[u] = calc(val[u], _tag);
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
  mnm[u] = inf;
  tag[u] = -1;
  if (_l == _r) {
    int aa = a[_l], bb = b[_l];
    push(val[u], bb);
    mnm[u] = calc(val[u], aa);
    return;
  }
  int _m = (_l + _r) / 2;
  build(ls(u), _l, _m);
  build(rs(u), _m + 1, _r);
  val[u] = val[ls(u)] + val[rs(u)];
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
  if (l[u] > _r || r[u] < _l) return inf * inf;
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