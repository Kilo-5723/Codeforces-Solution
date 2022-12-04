#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
ll _abs(ll n) { return n < 0 ? -n : n; }
struct value {
  ll al, ar, sum;
};
const value null{inf, inf, 0};
bool isnull(const value &a) { return a.al == null.al; }
value add(const value &a, const value &b) {
  if (isnull(a)) return b;
  if (isnull(b)) return a;
  return {a.al, b.ar,
          a.sum + b.sum + max(_abs(a.ar + b.al), _abs(a.ar - b.al))};
}
struct SegTree {
  struct node {
    int l, r;
    node *ls, *rs;
    value v;
  };
  void update(node *u) { u->v = add(u->ls->v, u->rs->v); }
  node *root = NULL;
  void build(node *&u, int l, int r, vector<ll> &a) {
    u = new node{l, r, NULL, NULL, null};
    if (l == r) {
      u->v = {a[l], a[l], 0};
      return;
    }
    int m = l + (r - l) / 2;
    build(u->ls, l, m, a);
    build(u->rs, m + 1, r, a);
    update(u);
  }
  bool exclude(node *u, int l, int r) { return u->l > r || u->r < l; }
  bool contain(node *u, int l, int r) { return u->l >= l && u->r <= r; }
  void modify(node *u, int p, ll a) {
    if (exclude(u, p, p)) return;
    if (contain(u, p, p)) {
      u->v = {a, a, 0};
      return;
    }
    modify(u->ls, p, a);
    modify(u->rs, p, a);
    update(u);
  }
  value query(node *u, int l, int r) {
    if (exclude(u, l, r)) return null;
    if (contain(u, l, r)) return u->v;
    return add(query(u->ls, l, r), query(u->rs, l, r));
  }
};
struct ChainTree {
  vector<int> dep, fa, son, siz;
  vector<int> ch, pos;
  vector<int> a;
  vector<vector<int>> e;
  vector<SegTree> val;
  void init(int n) {
    dep.resize(n + 1);
    ch.resize(n + 1);
    fa.resize(n + 1);
    son.resize(n + 1);
    pos.resize(n + 1);
    siz.resize(n + 1);
    a.resize(n + 1);
    e.resize(n + 1);
    val.resize(n + 1);
  }
  void dfs1(int u, int f) {
    siz[u] = 1;
    son[u] = 0;
    ch[u] = u;
    for (auto v : e[u])
      if (v != f) {
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        siz[u] += siz[v];
        fa[v] = u;
        if (siz[v] > siz[son[u]]) son[u] = v;
      }
    ch[son[u]] = 0;
  }
  void dfs2(int u, int f) {
    if (ch[u] == u) {
      vector<ll> arr;
      for (int v = u; v; v = son[v]) {
        ch[v] = u;
        pos[v] = dep[v] - dep[u];
        arr.push_back(a[v]);
      }
      val[u].build(val[u].root, 0, arr.size() - 1, arr);
    }
    for (auto v : e[u])
      if (v != f) dfs2(v, u);
  }
  void build() {
    dep[1] = 0;
    fa[1] = 0;
    dfs1(1, 1);
    dfs2(1, 1);
  }
  void modify(int u, int a) {
    auto &sgt = val[ch[u]];
    sgt.modify(sgt.root, pos[u], a);
  }
  ll query(int u, int v) {
    value vu = null, vv = null;
    while (ch[u] != ch[v]) {
      if (dep[ch[u]] > dep[ch[v]]) {
        swap(u, v);
        swap(vu, vv);
      }
      auto &sgt = val[ch[v]];
      vv = add(sgt.query(sgt.root, 0, pos[v]), vv);
      v = fa[ch[v]];
    }
    if (dep[u] > dep[v]) {
      swap(u, v);
      swap(vu, vv);
    }
    swap(vu.al, vu.ar);
    auto res = vu;
    auto &sgt = val[ch[u]];
    res = add(res, sgt.query(sgt.root, pos[u], pos[v]));
    res = add(res, vv);
    return res.sum;
  }
};
ChainTree tree;
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  ChainTree tree;
  tree.init(n);
  for (int i = 1; i <= n; i++) scanf("%d", &tree.a[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    tree.e[u].push_back(v);
    tree.e[v].push_back(u);
  }
  tree.build();
  while (q--) {
    int op, u, v;
    scanf("%d%d%d", &op, &u, &v);
    switch (op) {
      case 1:
        tree.modify(u, v);
        break;
      case 2:
        printf("%lld\n", tree.query(u, v));
        break;
    }
  }
  return 0;
}