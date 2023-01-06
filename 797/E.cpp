#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int limit = 300;
const int inf = 1e9;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  vector dp(limit, vector<int>(n + 1, inf));
  for (int k = 1; k < limit; k++) {
    for (int i = n; i >= 1; i--)
      if (i + a[i] + k > n)
        dp[k][i] = 1;
      else
        dp[k][i] = dp[k][i + a[i] + k] + 1;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int p, k;
    scanf("%d%d", &p, &k);
    int ans = 0;
    if (k < limit) {
      printf("%d\n", dp[k][p]);
      continue;
    }
    while (p <= n) {
      p += a[p] + k;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}