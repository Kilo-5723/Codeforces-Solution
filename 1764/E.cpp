#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
struct node {
  int l, r;
  node *ls, *rs;
  ll mnm;
  bool exclude(int _l, int _r) { return l > _r || r < _l; }
  bool include(int _l, int _r) { return l >= _l && r <= _r; }
};
node *root;
void build(int l, int r, const vector<ll> &a, node *&u = root) {
  u = new node{l, r, NULL, NULL, 0};
  if (l == r) {
    u->mnm = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(l, m, a, u->ls);
  build(m + 1, r, a, u->rs);
  u->mnm=min(u->ls->mnm,u->rs->mnm);
}
int query(int l, int r, int v, node *&u = root) {
  if (u->mnm >= v) return -1;
  if (u->exclude(l, r)) return -1;
  if (u->l == u->r) return u->l;
  int res = query(l, r, v, u->rs);
  if (~res) return res;
  return query(l, r, v, u->ls);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) scanf("%d%d", &arr[i].first, &arr[i].second);
    if (k <= arr[0].first) {
      puts("YES");
      continue;
    }
    if (n == 1 || k > arr[0].first + arr[0].second) {
      puts("NO");
      continue;
    }
    k -= arr[0].second;
    n--;
    arr.erase(arr.begin());
    sort(arr.begin(), arr.end(), [](auto a, auto b) {
      return a.first + a.second < b.first + b.second;
    });
    root = NULL;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      a[i] = arr[i].first;
      b[i] = arr[i].second;
    }
    // int t = k;
    vector<ll> c(n), d(n);
    d[n - 1] = 0;
    for (int i = n - 1; i; i--) d[i - 1] = d[i] + b[i];
    for (int i = n - 1; i >= 0; i--) {
      c[i] = a[i] + b[i] - k + d[i];
    }
    build(0, n - 1, c);
    bool flg = false;
    for (int i = 0; i < n; i++) {
      int u = query(i + 1, n - 1, 0);
      ll lim;
      if (~u) {
        lim = k - d[u];
      } else {
        u = query(0, i - 1, b[i]);
        if (~u) {
          lim = k - d[u] + b[i];
        } else {
          lim = k - d[0] - b[0] + b[i];
        }
      }
      // printf("lim : %lld\n",lim);
      if (lim <= a[i]) flg = true;
    }
    puts(flg ? "YES" : "NO");
  }
  return 0;
}