#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 5;
struct node {
  ll l, r;
  ll sum, cnt;
  node *ls, *rs;
  node(ll l, ll r) : l(l), r(r) {
    sum = cnt = 0;
    ls = rs = NULL;
  }
};
void push_down(node *u) {
  if (u->l == u->r || u->ls) return;
  ll m = u->l + (u->r - u->l) / 2;
  u->ls = new node(u->l, m);
  u->rs = new node(m + 1, u->r);
}
void add(node *u, ll val) {
  if (val < u->l || val > u->r) return;
  // cout << u->l << ' ' << u->r << endl;
  u->sum += val;
  u->cnt++;
  if (u->l == u->r) return;
  push_down(u);
  add(u->ls, val);
  add(u->rs, val);
}
ll query_sum(node *u, ll l, ll r) {
  if (!u || u->l > r || u->r < l) return 0;
  if (u->l >= l && u->r <= r) return u->sum;
  return query_sum(u->ls, l, r) + query_sum(u->rs, l, r);
}
ll query_cnt(node *u, ll l, ll r) {
  if (!u || u->l > r || u->r < l) return 0;
  if (u->l >= l && u->r <= r) return u->cnt;
  return query_cnt(u->ls, l, r) + query_cnt(u->rs, l, r);
}
char s[maxn];
ll a[maxn], p[maxn];
ll f[maxn], l[maxn], r[maxn];
node *rt[maxn];
bool vis[maxn];
ll ff(ll u) { return f[u] == u ? u : f[u] = ff(f[u]); }
ll ans;
void clear(node *u) {
  if (!u) return;
  clear(u->ls);
  clear(u->rs);
  delete u;
}
void comb(ll u, ll v, ll val) {
  u = ff(u);
  v = ff(v);
  if (u == v) return;
  if (r[u] - l[u] < r[v] - l[v]) swap(u, v);
  for (ll i = l[v]; i <= r[v]; i++) {
    ll d = query_cnt(rt[u], a[i], maxn);
    ans += d * (a[i] - val);
    ll s = query_sum(rt[u], -maxn, a[i] - 1);
    d = query_cnt(rt[u], -maxn, a[i] - 1);
    ans += s - d * val;
  }
  f[v] = u;
  l[u] = min(l[u], l[v]);
  r[u] = max(r[u], r[v]);
  for (ll i = l[v]; i <= r[v]; i++) add(rt[u], a[i]);
  clear(rt[v]);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (ll i = 0; i < n; i++) a[i + 1] = a[i] + (s[i] == '(' ? 1 : -1);
    for (ll i = 0; i <= n; i++) {
      f[i] = l[i] = r[i] = p[i] = i;
      rt[i] = NULL;
    }
    sort(p, p + n + 1, [](ll i, ll j) { return a[i] > a[j]; });
    // for (ll i = 0; i <= n; i++) prllf("%d %d\n", p[i], a[p[i]]);
    // puts("");
    ans = 0;
    ll sum = 0;
    for (ll i = 0; i <= n; i++) {
      ans += (sum - a[p[i]] * i);
      sum += a[p[i]];
    }
    // prllf("%lld\n", ans);
    for (ll i = 0; i <= n; i++) {
      ll u = p[i];
      rt[u] = new node(-maxn, maxn);
      add(rt[u], a[u]);
      if (u > 0 && rt[u - 1]) comb(u, u - 1, a[u]);
      if (u < n && rt[u + 1]) comb(u, u + 1, a[u]);
    }
    clear(rt[ff(0)]);
    printf("%lld\n", ans);
    // ll ans = 0;
    // for (ll i = 0; i <= n; i++)
    //   for (ll j = i; j <= n; j++) {
    //     ll p = i;
    //     for (ll k = i; k <= j; k++)
    //       if (a[k] < a[p]) p = k;
    //     ans += abs(a[j] - a[i]) + (min(a[i], a[j]) - a[p] + 1) / 2;
    //   }
    // prllf("%d\n", ans);
  }
  return 0;
}