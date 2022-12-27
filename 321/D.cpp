#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int inf = 1e9;
int calc(const vector<int> &a) {
  int n = a.size(), m = n / 2 + 1;
  int res = -inf;
  for (auto b : {-1, 1}) {
    int tmp = a[m - 1] * b;
    for (int i = 0; i < m - 1; i++) tmp += abs(a[i] + a[i + m] * b);
    res = max(res, tmp);
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  int m = n / 2 + 1;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  if (n == 1) {
    printf("%d\n", abs(a[0][0]));
    return 0;
  }
  int ans = 0;
  for (ll b = 0; b < (1 << m); b++) {
    ll x = 0;
    for (int i = 0; i < m; i++) x ^= b << i;
    int res = 0;
    for (int i = 0; i < n; i++) res += a[m - 1][i] * ((x >> i & 1) ? -1 : 1);
    for (int i = 0; i < m - 1; i++) {
      vector<int> tmp(n);
      for (int j = 0; j < n; j++)
        tmp[j] = a[i][j] + a[i + m][j] * ((x >> j & 1) ? -1 : 1);
      res += calc(tmp);
    }
    ans = max(ans, res);
  }
  printf("%d\n", ans);
  return 0;
}