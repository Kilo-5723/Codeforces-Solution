#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int buff = 10;
char s[buff];
int main() {
  int n;
  scanf("%d", &n);
  vector<ll> a, b, c;
  while (n--) {
    ll t;
    scanf("%lld%s", &t, s);
    switch (s[0]) {
      case 'R':
        a.push_back(t);
        break;
      case 'B':
        b.push_back(t);
        break;
      case 'P':
        c.push_back(t);
        break;
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  if (!c.size()) {
    ll ans = 0;
    if (a.size()) ans += a.back() - a[0];
    if (b.size()) ans += b.back() - b[0];
    printf("%lld\n", ans);
    return 0;
  }
  a.push_back(inf);
  reverse(a.begin(), a.end());
  b.push_back(inf);
  reverse(b.begin(), b.end());
  ll ans = c.back() - c[0];
  c.push_back(inf);
  ll las = -inf;
  for (auto v : c) {
    ll tlas, mxm, tsum = 0;
    tlas = las;
    mxm = 0;
    while (a.back() < v) {
      mxm = max(mxm, a.back() - tlas);
      tlas = a.back();
      a.pop_back();
    }
    mxm = max(mxm, v - tlas);

    tsum += v - las - mxm;
    tlas = las;
    mxm = 0;
    while (b.back() < v) {
      mxm = max(mxm, b.back() - tlas);
      tlas = b.back();
      b.pop_back();
    }
    mxm = max(mxm, v - tlas);
    tsum += v - las - mxm;
    ans += min(tsum, v - las);
    las = v;
  }
  printf("%lld\n", ans);
  return 0;
}