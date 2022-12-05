#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 505;
ll C[maxn][maxn], dp[maxn][maxn], way[maxn][maxn];
ll gway(int i, int j) {
  if (!i && !j) return 1;
  if (i < 0) return 0;
  if (j < 0) return 0;
  if (way[i][j]) return way[i][j];
  return way[i][j] =
             (gway(i - 1, j) + gway(i, j - 1) + gway(i - 1, j - 1)) % mod;
}
ll comb(int i, int j) {
  if (!i && !j) return 1;
  if (i < 0) return 0;
  if (j < 0) return 0;
  if (dp[i][j]) return dp[i][j];
  return dp[i][j] = (comb(i - 1, j) + comb(i, j - 1) + comb(i - 1, j - 1) +
                     gway(i, j)) %
                    mod;
}
ll neww(int i, int j) {
  // if (!i && !j) return 1;
  if (i < 0) return 0;
  if (j < 0) return 0;
  return comb(i, j) / (i + 1);
}
int main() {
  for (int i = 0; i < maxn; i++) C[i][0] = C[i][i] = 1;
  for (int i = 1; i < maxn; i++)
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  int tt;
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++)
      // printf("%7lld ", comb(i, j) / ((i + 1)));
      printf("%7lld ",
             neww(i, j) - neww(i, j - 1) - neww(i - 1, j) - neww(i - 1, j - 1));
    puts("");
  }
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n < m) swap(n, m);
    ll ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        ans += C[n - 1][i] * C[m - 1][j] % mod * comb(i + 1, j + 1) % mod;
    printf("%lld\n", ans % mod);
  }
  return 0;
}