#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> a(n, vector<int>(n, 0));
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    if (t == 2) {
      puts("0");
      return 0;
    }
    for (int j = i; j < n; j++) scanf("%d", &a[i][j]);
  }
  // for (int i = 1; i < n; i++) {
  //   for (int j = 1; j < n; j++) cout << a[i][j] << ' ';
  //   cout << endl;
  // }
  int l = 0;
  vector<ll> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = l; j < i; j++) dp[i] += dp[j];
    dp[i] %= mod;
    for (int x = 1; x <= i; x++)
      for (int y = i; y < n; y++)
        if (a[x][y] == 1) dp[i] = 0;
    // printf("%lld ", dp[i]);
    for (int j = 1; j <= i; j++)
      if (a[j][i] == 2) l = max(l, j);
  }
  ll ans = 0;
  for (int i = l; i <= n; i++) ans += dp[i];
  printf("%lld\n", ans * 2 % mod);
  return 0;
}