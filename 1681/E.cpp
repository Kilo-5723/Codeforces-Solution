#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int main() {
  int n;
  scanf("%d", &n);
  vector<ll> x(n - 1), y(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    y[x1 - 1] = y1 - 1;
    x[y2 - 1] = x2 - 1;
  }
  vector dp(n - 1, vector(1, vector(2, vector<ll>(2))));
  for (int i = 1; i < n - 1; i++) {
    dp[i][0][0][0] = abs(x[i] - x[i - 1]) + 1;
    dp[i][0][1][1] = abs(y[i] - y[i - 1]) + 1;
    dp[i][0][0][1] =
        min(dp[i][0][0][0] + abs(i - 1 - x[i - 1]) + abs(i - 1 - y[i - 1]),
            abs(i - x[i]) + abs(i - y[i - 1]) + 1);
    dp[i][0][1][0] =
        min(dp[i][0][1][1] + abs(i - 1 - x[i - 1]) + abs(i - 1 - y[i - 1]),
            abs(i - y[i]) + abs(i - x[i - 1]) + 1);
  }
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; (1 << j) <= i; j++) {
      dp[i].push_back(vector(2, vector<ll>(2, inf)));
      for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
          for (int k = 0; k < 2; k++)
            dp[i][j][x][y] =
                min(dp[i][j][x][y],
                    dp[i][j - 1][x][k] + dp[i - (1 << j - 1)][j - 1][k][y]);
    }
  int m;
  scanf("%d", &m);
  while (m--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--;
    y1--;
    x2--;
    y2--;
    if (max(x1, y1) < max(x2, y2)) {
      swap(x1, x2);
      swap(y1, y2);
    }
    if (max(x1, y1) == max(x2, y2)) {
      printf("%d\n", abs(x1 - x2) + abs(y1 - y2));
      continue;
    }
    vector<ll> dis(2);
    int p = max(x1, y1) - 1, q = max(x2, y2);
    dis[0] = abs(x1 - x[p]) + abs(y1 - p - 1) + 1;
    dis[1] = abs(x1 - p - 1) + abs(y1 - y[p]) + 1;
    for (int i = 0; (1 << i) <= p - q; i++)
      if (p - q >> i & 1) {
        vector<ll> nxt(2, inf);
        for (int x = 0; x < 2; x++)
          for (int k = 0; k < 2; k++)
            nxt[k] = min(nxt[k], dis[x] + dp[p][i][x][k]);
        dis = nxt;
        p -= 1 << i;
      }
    ll ans = min(dis[0] + abs(x2 - x[q]) + abs(y2 - q),
                 dis[1] + abs(x2 - q) + abs(y2 - y[q]));
    printf("%lld\n", ans);
  }
  return 0;
}