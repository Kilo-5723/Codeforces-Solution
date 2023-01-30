#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) scanf("%lld", &c[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
    for (int i = 0; i < n; i++)
      if (a[i] > b[i]) swap(a[i], b[i]);
    ll cur = -inf, ans = 0;
    for (int i = 1; i < n; i++) {
      cur += (a[i] + c[i - 1] - b[i] + 1);
      if (a[i] == b[i]) cur = 1;
      cur = max(cur, b[i] - a[i] + 1);
      ans = max(ans, cur + c[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}