#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
void fwt(vector<ll> &a) {
  for (int d = a.size() / 2; d; d >>= 1)
    for (int i = 0; i < a.size(); i += 2 * d)
      for (int j = 0; j < d; j++) a[i + d + j] = min(a[i + j], a[i + d + j]);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (auto &v : a) v--;
  vector<ll> e(m);
  for (int i = 1; i < n; i++) {
    e[a[i - 1]] |= 1LL << a[i];
    e[a[i]] |= 1LL << a[i - 1];
  }
  e[a[0]] |= 1LL << a[0];
  e[a[n - 1]] |= 1LL << a[n - 1];
  vector<ll> c(m);
  for (int i = 0; i < m; i++) scanf("%lld", &c[i]);
  ll adder = 0;
  int p = m / 2;
  vector<ll> x(1LL << m - p);
  for (ll b = 0; b < 1LL << m; b += 1LL << p) {
    ll st = 0;
    for (int i = p; i < m; i++)
      if (b >> i & 1)
        st |= e[i];
      else
        x[b >> p] += c[i];
    if (st & b) x[b >> p] += inf;
  }
  fwt(x);
  ll ans = inf;
  for (ll b = 0; b < (1 << p); b++) {
    ll st = 0;
    ll cost = 0;
    for (int i = 0; i < p; i++)
      if (b >> i & 1)
        st |= e[i];
      else
        cost += c[i];
    if (!(st & b)) ans = min(ans, cost + x[(~st >> p) & (1 << m - p) - 1]);
  }
  printf("%lld\n", ans);
  return 0;
}