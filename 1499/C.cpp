#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
vector<ll> solve(const vector<ll> &a, int n) {
  ll cur = 0, mnm = a[0];
  vector<ll> res;
  for (int i = 0; i < a.size(); i++) {
    cur += a[i];
    mnm = min(mnm, a[i]);
    res.push_back(cur + mnm * (n - i - 1));
  }
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    vector<ll> b, c;
    for (int i = 0; i < n; i += 2) b.push_back(a[i]);
    for (int i = 1; i < n; i += 2) c.push_back(a[i]);
    b = solve(b, n);
    c = solve(c, n);
    for (int i = 0; i < n; i++) a[i] = (i & 1 ? c : b)[i / 2];
    ll ans = a[0] + a[1];
    for (int i = 1; i < n; i++) ans = min(ans, a[i] + a[i - 1]);
    printf("%lld\n", ans);
  }
  return 0;
}