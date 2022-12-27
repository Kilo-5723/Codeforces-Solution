#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
bool playone(const vector<ll> &a, ll x, ll y) {
  int cnt = 0;
  for (auto v : a)
    if (v <= x) {
      x++;
      cnt++;
      if (x >= y) {
        printf("%d\n", cnt);
        return true;
      }
    }
  return false;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    ll x, y;
    scanf("%d%lld%lld", &n, &x, &y);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      a[i] = min(a[i], y);
    }
    sort(a.begin(), a.end());
    if (playone(a, x, y)) continue;
    ll ans = 0;
    bool flg = false;
    for (int i = 0; i < n; i++) {
      if (a[i] > x) {
        if (i <= n - i) {
          puts("-1");
          x = y;
          break;
        }
        ll t = (a[i] - x - 1) / (i - n + i);
        x += t * (i - n + i);
        ans += t * n;
        if (x + i - n + i >= y) {
          printf("%lld\n", ans + (n - i) * 2 + y - x);
          x = y;
          break;
        }
        x += (i - n + i);
        ans += n;
      }
      x++;
      ans++;
      if (x >= y) {
        printf("%lld\n", ans);
        break;
      }
    }
    if (x < y) printf("%lld\n", ans + (y - x));
  }
  return 0;
}