#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
void solve(ll &a, ll b) {
  if (a > b) return;
  a = (a + b + 1) / 2;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll h;
    scanf("%lld", &h);
    vector<ll> a(n - 1);
    for (int i = 1; i < n; i++) scanf("%lld", &a[i - 1]);
    sort(a.begin(), a.end());
    for (auto v : a) solve(h, v);
    printf("%lld\n", h);
  }
  return 0;
}