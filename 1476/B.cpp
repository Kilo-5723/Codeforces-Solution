#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e16;
bool check(const vector<ll> &a, ll m, int k) {
  for (int i = 1; i < a.size(); i++)
    if ((a[i - 1] + m) * (100 + k) < (a[i] + m) * 100) return false;
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i < n; i++) a[i] += a[i - 1];
    ll l = -1, r = inf;
    while (r - l > 1) {
      ll m = (l + r) / 2;
      if (check(a, m, k))
        r = m;
      else
        l = m;
    }
    printf("%lld\n", r);
  }
  return 0;
}