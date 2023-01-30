#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll solve(vector<ll> &s, vector<ll> &c, int i, int j, ll k) {
  ll co = c.back() - c[j] + c[i];
  ll lim = k * co + s.back();
  return min((c[j] - c[i]) * k, lim) + s[i] - s[j];
}
int main() {
  int n;
  ll k;
  scanf("%d%lld", &n, &k);
  vector<ll> a(n);
  vector<ll> s(n + 1), c(n + 1);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    s[i + 1] = s[i] + a[i];
    c[i + 1] = c[i] + !a[i];
  }
  if (s.back() > k * c.back() || s.back() < -k * c.back()) {
    puts("-1");
    return 0;
  }
  ll ans = 0;
  for (int i = 0; i <= n; i++)
    for (int j = i + 1; j <= n; j++) ans = max(ans, solve(s, c, i, j, k));
  for (auto &v : s) v = -v;
  for (int i = 0; i <= n; i++)
    for (int j = i + 1; j <= n; j++) ans = max(ans, solve(s, c, i, j, k));
  printf("%lld\n", ans + 1);
  return 0;
}