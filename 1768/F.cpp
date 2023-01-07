#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int main() {
  int n;
  scanf("%d", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  vector<ll> dp(n, inf);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i - 1; j >= 0 && a[i] * (i - j - 1) <= n; j--) {
      dp[i] = min(dp[i], dp[j] + min(a[i], a[j]) * (j - i) * (j - i));
      if (a[j] <= a[i]) break;
    }
    for (int j = i + 1; j < n && a[i] * (j - i - 1) <= n; j++) {
      dp[j] = min(dp[j], dp[i] + min(a[i], a[j]) * (j - i) * (j - i));
      if (a[j] <= a[i]) break;
    }
  }
  for (auto v : dp) printf("%lld ", v);
  puts("");
  return 0;
}