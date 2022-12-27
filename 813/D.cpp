#include <assert.h>

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9, maxk = 1e5 + 5;
const int m = 7;
void pass(int &a, int b) { a = max(a, b); }
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<int> id(maxk);
  int k;
  for (auto v : a)
    if (!id[v]) id[v] = ++k;
  vector<vector<int>> dpi(k + 1, vector<int>(n, -inf));
  vector<vector<int>> dpv(m, vector<int>(n, -inf));
  vector<int> dps(n, -inf);
  for (int i = 0; i < n; i++) {
    vector<int> dp(n, -inf);
    for (int j = 0; j < i; j++) pass(dp[j], dps[j] + 1);
    dps[i] = 0;
    for (int j = 0; j < i; j++)
      if ((a[i] - a[j]) % m == 0 || a[i] - a[j] == 1 || a[i] - a[j] == -1)
        pass(dps[i], dps[j]);
    dps[i]++;
    for (int j = 0; j < i; j++) pass(dp[j], dpv[a[i] % m][j] + 1);
    for (int j = 0; j < i; j++) pass(dp[j], dpi[id[a[i] - 1]][j] + 1);
    for (int j = 0; j < i; j++) pass(dp[j], dpi[id[a[i] + 1]][j] + 1);
    for (int j = 0; j < i; j++) {
      pass(dpi[id[a[i]]][j], dp[j]);
      pass(dpi[id[a[j]]][i], dp[j]);
      pass(dpv[a[i] % m][j], dp[j]);
      pass(dpv[a[j] % m][i], dp[j]);
    }
  }
  int ans = -inf;
  for (auto &arr : dpv)
    for (auto v : arr) ans = max(ans, v);
  printf("%d\n", ans);
  return 0;
}