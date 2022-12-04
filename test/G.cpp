#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
void uniform(vector<pair<int, int>> &arr, map<int, int> &xid,
             map<int, int> &yid) {
  for (auto &[x, y] : arr) {
    x = xid[x];
    y = yid[y];
  }
}
int lowbit(int n) { return n & -n; }
int sum(vector<int> &a, int n) {
  int res = 0;
  for (int i = n; i; i -= lowbit(i)) res += a[i];
  return res;
}
void add(vector<int> &a, int n, int v) {
  for (int i = n; i < a.size(); i += lowbit(i)) a[i] += v;
}
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll f(int n) { return 1; }
ll f(int x, int y, map<pair<int, int>, int> &ans) {
  return f(ans[{x, y}]) - f(ans[{x + 1, y}]) - f(ans[{x, y - 1}]) +
         f(ans[{x + 1, y - 1}]);
}
ll g(int n) { return 1; }
ll g(int x, int y, map<pair<int, int>, int> &ans) {
  return g(ans[{x, y}]) - g(ans[{x + 1, y}]) - g(ans[{x, y - 1}]) +
         g(ans[{x + 1, y - 1}]);
}
ll t(int x, int y, map<pair<int, int>, int> &ans) {
  return (ans[{x, y}] == 0) - (ans[{x + 1, y}] == 0) - (ans[{x, y - 1}] == 0) +
         (ans[{x + 1, y - 1}] == 0);
}
int main() {
  int m, q;
  scanf("%d%d", &m, &q);
  vector<pair<int, int>> arr;
  map<int, int> xid, yid;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    arr.push_back({x, y});
  }
  for (auto [x, y] : arr) xid[x] = yid[y] = 0;
  vector<pair<int, int>> qry;
  vector<pair<int, int>> chk;
  for (int i = 0; i < q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    qry.push_back({x, y});
    chk.push_back({x, y});
    chk.push_back({x, y - 1});
    chk.push_back({x + 1, y});
    chk.push_back({x + 1, y - 1});
  }
  for (auto [x, y] : chk) xid[x] = yid[y] = 0;
  int rx = 0, ry = 0;
  for (auto &[k, v] : xid) v = ++rx;
  for (auto &[k, v] : yid) v = ++ry;
  uniform(arr, xid, yid);
  uniform(qry, xid, yid);
  uniform(chk, xid, yid);
  sort(arr.begin(), arr.end());
  reverse(arr.begin(), arr.end());
  sort(chk.begin(), chk.end());
  chk.resize(unique(chk.begin(), chk.end()) - chk.begin());
  reverse(chk.begin(), chk.end());
  for (auto [x, y] : arr) printf("arr: %d %d\n", x, y);
  for (auto [x, y] : qry) printf("qry: %d %d\n", x, y);
  for (auto [x, y] : chk) printf("chk: %d %d\n", x, y);
  vector<int> bit(ry + 1);
  map<pair<int, int>, int> ans;
  int la = 0, ra = 0, lc = 0, rc = 0;
  for (int i = rx; i >= 1; i--) {
    la = ra;
    while (ra < arr.size() && arr[ra].first >= i) ra++;
    lc = rc;
    while (rc < chk.size() && chk[rc].first >= i) rc++;
    cout << "arr: " << la << ',' << ra << "  chk: " << lc << ',' << rc << endl;
    for (int k = la; k < ra; k++) {
      int j = arr[k].second;
      add(bit, j, 1);
      printf("add: %d %d\n", i, j);
    }
    for (int k = lc; k < rc; k++) {
      int j = chk[k].second;
      ans[{i, j}] = sum(bit, j);
      printf("sum: %d %d %d\n", i, j, ans[{i, j}]);
    }
  }
  for (auto [x, y] : qry) {
    printf("%lld\n", (t(x, y, ans) % mod + mod) % mod);
  }
  return 0;
}