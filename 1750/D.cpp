#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
map<ll, vector<ll>> prime;
ll solve(ll m, ll n) {
  vector<ll> p;
  ll t = m;
  for (ll i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      p.push_back(i);
      while (m % i == 0) m /= i;
    }
  }
  if (m > 1) p.push_back(m);
  ll sz = p.size();
  ll sum = 0;
  for (ll i = 1; i < (1 << sz); i++) {
    ll ct = 0;
    ll mul = 1;
    for (ll j = 0; j < sz; j++) {
      if (i & (1LL << j)) {
        ct++;
        mul *= p[j];
      }
    }
    if (ct & 1)
      sum += n / mul;
    else
      sum -= n / mul;
  }
  return n - sum;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll las = 0, ans = 1;
    ll n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < n; i++) {
      ll a;
      scanf("%lld", &a);
      if (!las)
        las = a;
      else if (a == las)
        ans = ans * (m / a) % mod;
      else if (las % a) {
        ans = 0;
        for (int j = i + 1; j < n; j++) scanf("%lld", &a);
        break;
      } else
        ans = ans * solve(las / a, m / a) % mod;
      las = a;
    }
    printf("%lld\n", (ans % mod + mod) % mod);
  }
  return 0;
}