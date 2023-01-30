#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int buff = 1e3 + 5;
char s[buff], t[buff];
ll calc(char s[]) {
  ll res = 0, cur = 1;
  for (int i = 1; s[i]; i++) {
    if (s[i] == s[i - 1]) {
      res += 1ll * cur * (cur + 1) / 2;
      cur = 0;
    }
    cur++;
  }
  res += 1ll * cur * (cur + 1) / 2;
  return res;
}
int main() {
  scanf("%s", s);
  scanf("%s", t);
  int n = strlen(s), m = strlen(t);
  vector dp(n + 1, vector(m + 1, vector<ll>{1, 0, 0}));
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      if (i < n) {
        dp[i + 1][j][1] += dp[i][j][0];
        if (i < n && i && s[i] != s[i - 1]) dp[i + 1][j][1] += dp[i][j][1];
        if (j && s[i] != t[j - 1]) dp[i + 1][j][1] += dp[i][j][2];
        dp[i + 1][j][1] %= mod;
      }
      if (j < m) {
        dp[i][j + 1][2] += dp[i][j][0];
        if (j < m && j && t[j] != t[j - 1]) dp[i][j + 1][2] += dp[i][j][2];
        if (i && t[j] != s[i - 1]) dp[i][j + 1][2] += dp[i][j][1];
        dp[i][j + 1][2] %= mod;
      }
    }
  ll ans = -(n + 1) * (m + 1);
  ans -= calc(s) * (m + 1);
  ans -= calc(t) * (n + 1);
  ans %= mod;
  for (auto &arr : dp)
    for (auto &brr : arr)
      for (auto v : brr) ans += v;
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}