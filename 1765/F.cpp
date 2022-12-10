#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct sol {
  int x, w, c;
};
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<sol> a(n);
  for (int i = 0; i < n; i++) scanf("%d%d%d", &a[i].x, &a[i].w, &a[i].c);
  sort(a.begin(), a.end(), [](auto a, auto b) { return a.x < b.x; });
  vector<double> dp(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i] = max(dp[i], dp[j] + (a[i].c + a[j].c) / 2.0 * (a[i].x - a[j].x) /
                                     100.0 * k);
    }
    dp[i] -= a[i].w;
    // printf("%.12f ", dp[i]);
  }
  double ans = 0;
  for (auto v : dp) ans = max(ans, v);
  printf("%.12f\n", ans);
  return 0;
}