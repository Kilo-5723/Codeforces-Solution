#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int n;
  scanf("%d", &n);
  vector<ll> dp(n + 1), las(n + 1);
  for (int i = 1; i <= n; i++) {
    ll t = 2;
    for (int j = 2; j * (j - 1) / 2 <= i; j++)
      if (dp[i - j * (j - 1) / 2] + j < dp[i - t * (t - 1) / 2] + t) t = j;
    dp[i] = dp[i - t * (t - 1) / 2] + t;
    las[i] = t;
  }
  ll ans = dp[n], sum = 0;
  for (int i = n; i; i -= las[i] * (las[i] - 1) / 2)
    sum += las[i] * (ans - las[i]);
  printf("%lld %lld\n", ans, sum / 2);
  return 0;
}