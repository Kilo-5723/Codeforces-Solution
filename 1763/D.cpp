#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int n, p, q, x, y;
bool check(int i, int v) {
  return i >= 0 && i < n && (i != p || x == v) && (i != q || y == v);
}
ll dfs(int l, int r, int c, vector<vector<ll>> &dp) {
  if (!c) return 1;
  if (~dp[l][r]) return dp[l][r];
  ll res = 0;
  if (check(l - 1, c)) res += dfs(l - 1, r, c - 1, dp);
  if (check(r + 1, c)) res += dfs(l, r + 1, c - 1, dp);
  return dp[l][r] = res % mod;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%d%d%d%d", &n, &p, &q, &x, &y);
    p--;
    q--;
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    ll ans = 0;
    for (int i = 1; i < n-1; i++)
      if (check(i, n)) ans += dfs(i, i, n - 1, dp);
    printf("%lld\n", ans % mod);
  }
  return 0;
}