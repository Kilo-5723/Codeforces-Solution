#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll solve(ll n, ll x) {
  if (x & 1) {
    if (!(n & 1)) return -1;
    ll res = solve(n >> 1, x >> 1) << 1;
    return (n & res) == x ? res : -1;
  }
  if (n == x) return n + 1;
  ll res = solve(n >> 1, x >> 1) << 1;
  return (n & res) == x ? res : -1;
  // return 0;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n, x;
    scanf("%lld%lld", &n, &x);
    auto ans = n == x ? n : solve(n, x);
    printf("%lld\n", ans < 0 ? -1 : ans);
  }
  return 0;
}