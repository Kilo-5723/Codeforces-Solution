#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll calc(ll x, ll y, vector<ll> pfact) {
  if (!y) return 0;
  ll z = gcd(x, y);
  x /= z;
  y /= z;
  vector<ll> nfact;
  for (auto v : pfact)
    if (!(x % v)) nfact.push_back(v);
  pfact = nfact;
  ll step = y;
  for (auto v : pfact) step = min(step, y % v);
  return calc(x, y - step, pfact) + step;
}
int main() {
  ll x, y;
  scanf("%lld%lld", &x, &y);
  vector<ll> pfact;
  ll t = x;
  for (ll i = 2; i * i <= t; i++)
    if (!(t % i)) {
      pfact.push_back(i);
      while (!(t % i)) t /= i;
    }
  if (t != 1) pfact.push_back(t);
  printf("%lld\n", calc(x, y, pfact));
  return 0;
}