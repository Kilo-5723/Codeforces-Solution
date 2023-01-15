#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> split(ll a1, ll a2) {
  vector<ll> res;
  for (ll i = 1; i * i < a2 - a1; i++)
    if ((a2 - a1) % i == 0) {
      ll j = (a2 - a1) / i;
      if (i + j & 1) continue;
      ll k1 = (j - i) / 2, k2 = (j + i) / 2;
      if (k1 * k1 - a1 >= 0) res.push_back(k1 * k1 - a1);
    }
  return res;
}
ll _sqrt(ll n) {
  ll m = sqrt(n);
  while (m * m > n) m--;
  while (m * m <= n) m++;
  return m - 1;
}
bool issqr(ll n) {
  ll m = _sqrt(n);
  return m * m == n;
}
int solve(const vector<ll> &a, ll x) {
  int res = 0;
  for (auto v : a) res += issqr(v + x);
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
    sort(a.begin(), a.end());
    vector<ll> arr;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[i] != a[j]) {
          auto tmp = split(a[i], a[j]);
          arr.insert(arr.begin(), tmp.begin(), tmp.end());
        }
    map<ll, int> cnt;
    for (auto v : a) cnt[v]++;
    int ans = 0;
    for (auto [k, v] : cnt) ans = max(ans, v);
    for (auto x : arr) ans = max(ans, solve(a, x));
    printf("%d\n", ans);
  }
  return 0;
}