#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e9 + 5;
const ll mod1 = 1e9 + 7, mul1 = 43, mod2 = 1e9 + 9, mul2 = 53;
vector<int> ls = {0}, rs = {0};
vector<pair<int, int>> hsh = {{0, 0}};
pair<int, int> get_hsh(int a) {
  ll hsh1 = 1, hsh2 = 1;
  ll tm1 = mul1, tm2 = mul2;
  while (a) {
    if (a & 1) {
      hsh1 = hsh1 * tm1 % mod1;
      hsh2 = hsh2 * tm1 % mod2;
    }
    tm1 = tm1 * tm1 % mod1;
    tm2 = tm2 * tm2 % mod2;
    a >>= 1;
  }
  return {hsh1, hsh2};
}
int nnode(int n = 0) {
  ls.push_back(ls[n]);
  rs.push_back(rs[n]);
  hsh.push_back(hsh[n]);
  return ls.size() - 1;
}
pair<int, int> add(pair<int, int> a, pair<int, int> b) {
  return {(a.first + b.first) % mod1, (a.second + b.second) % mod2};
}
int modify(int u, int _l, int _r, int p) {
  // cout << "modify " << u << ' ' << _l << ' ' << _r << ' ' << p << endl;
  auto v = nnode(u);
  if (_l == _r) {
    if (hsh[v].first)
      hsh[v] = {0, 0};
    else
      hsh[v] = get_hsh(p);
    return v;
  }
  int _m = (_l + _r) / 2;
  if (p > _m)
    rs[v] = modify(rs[u], _m + 1, _r, p);
  else
    ls[v] = modify(ls[u], _l, _m, p);
  hsh[v] = add(hsh[ls[v]], hsh[rs[v]]);
  return v;
}
int query(int u, int v, int _l, int _r) {
  // cout << "query " << u << ' ' << v << ' ' << _l << ' ' << _r << endl;
  if (hsh[u] == hsh[v]) return 0;
  int _m = (_l + _r) / 2;
  if (_l == _r) return _l;
  if (hsh[ls[u]] != hsh[ls[v]])
    return query(ls[u], ls[v], _l, _m);
  else
    return query(rs[u], rs[v], _m + 1, _r);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> root = {nnode()};
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    root.push_back(modify(root[i], 0, maxn, t));
  }
  int m = 0;
  scanf("%d", &m);
  int ans = 0;
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a ^= ans;
    b ^= ans;
    printf("%d\n", ans = query(root[b], root[a - 1], 0, maxn));
  }
  return 0;
}