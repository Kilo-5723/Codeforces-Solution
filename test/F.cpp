#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll inf = 2e9;
ll solve(const vector<ll>& a, ll b) {
  if (b < 0) return 0;
  ll res = 0;
  for (auto v : a) {
    res = res * 2 % mod;
    if (b >= v) {
      b -= v;
      res++;
    }
  }
  return res + 1;
}
int main() {
  int n;
  vector<pair<int, ll>> a;
  scanf("%d", &n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    int t, v;
    scanf("%d", &t);
    switch (t) {
      case 1:
        scanf("%d", &v);
        a.push_back({t, v});
        break;
      case 2:
        scanf("%d", &v);
        a.push_back({t, v});
        sum += v;
        break;
      case 3:
        if (sum > inf) break;
        if (sum == 0) {
          a.push_back({4, 0});
          break;
        }
        a.push_back({t, sum});
        sum *= 2;
        break;
    }
  }
  ll cur = 0;
  vector<ll> rep;
  reverse(a.begin(), a.end());
  ll ans = 0, mul = 1;
  for (const auto& [t, v] : a) {
    switch (t) {
      case 1:
        ans += mul * solve(rep, v - cur - 1) % mod;
        break;
      case 2:
        cur += v;
        break;
      case 3:
        rep.push_back(v);
        break;
      case 4:
        mul = mul * 2 % mod;
        break;
    }
  }
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}