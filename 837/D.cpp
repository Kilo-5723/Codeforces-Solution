#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
const int inf = 1e9;
int dfs(int n, int k, int v, vector<int> &a, vector<int> &b,
        vector<vector<vector<int>>> &dp) {
  // cout << n << ' ' << k << ' ' << v << endl;
  if (!k) return v ? -inf : 0;
  if (n < 0) return -inf;
  if (~dp[n][k][v]) return dp[n][k][v];
  int res = dfs(n - 1, k, v, a, b, dp);
  if (v >= b[n]) res = max(res, dfs(n - 1, k - 1, v - b[n], a, b, dp)) + a[n];
  return dp[n][k][v] = res;
}
void read(int &a, int &b) {
  ll t;
  a = b = 0;
  scanf("%lld", &t);
  while (!(t % 2)) {
    a++;
    t /= 2;
  }
  while (!(t % 5)) {
    b++;
    t /= 5;
  }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int ans = 0;
  vector dp(k + 1, vector<int>(n * 30, -inf));
  dp[0][0] = 0;
  for (int t = 0; t < n; t++) {
    int a, b;
    read(a, b);
    for (int i = k; i >= 1; i--)
      for (int j = b; j < n * 30; j++)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - b] + a);
    for (int i = 0; i < n * 30; i++) ans = max(ans, min(i, dp[k][i]));
  }
  printf("%d\n", ans);
  return 0;
}