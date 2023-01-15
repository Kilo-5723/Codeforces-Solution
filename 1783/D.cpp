#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int lim = 300;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void add(ll &a, ll b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  int n;
  scanf("%d", &n);
  int base = n * lim;
  vector dp(n + 1, vector<ll>(base * 2 + 1, 0));
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  dp[1][a[1] + base] = 1;
  for (int i = 1; i < n - 1; i++) {
    for (int j = -base; j <= base; j++)
      if (dp[i][j + base]) {
        if (j) {
          add(dp[i + 1][a[i + 1] + j + base], dp[i][j + base]);
          add(dp[i + 1][a[i + 1] - j + base], dp[i][j + base]);
        } else {
          add(dp[i + 1][a[i + 1] + base], dp[i][j + base]);
        }
      }
  }
  ll ans = 0;
  for (int j = -base; j <= base; j++) ans += dp[n - 1][j + base];
  printf("%lld\n", ans % mod);
  return 0;
}