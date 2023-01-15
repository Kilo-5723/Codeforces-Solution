#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll mod;
int _sqrt(int n) {
  int m = sqrt(n);
  while (m * m <= n) m++;
  while (m * m > n) m--;
  return m;
}
void solve1(int n) {
  int w = _sqrt(n), h = (n - 1) / w + 1;
  printf("%d %d\n", w, h);
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) putchar(n-- > 0 ? '#' : '.');
    puts("");
  }
}

ll calc(ll m, ll n, vector<vector<ll>> &dp) {
  if (~dp[m][n]) return dp[m][n];
  if (!m) return 1;
  ll res = 0;
  for (int i = 1; i <= m && i <= n; i++) res += calc(m - i, i, dp);
  return dp[m][n] = res % mod;
}
vector<ll> mul(const vector<ll> &a, const vector<ll> &b) {
  int n = a.size(), m = b.size();
  vector<ll> c(n + m - 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) c[i + j] += a[i] * b[j] % mod;
  for (auto &v : c) v %= mod;
  return c;
}
vector<ll> res;
// ll cases(int e, vector<vector<ll>> &dp) {
//   vector<ll> res(e + 1);
//   for (int i = 0; i <= e; i++) res[i] = calc(i, i, dp);
//   for (int i = 0; i < 2; i++) {
//     res = mul(res, res);
//     res.resize(e + 1);
//   }
//   return res[e];
// }
void solve2(int n, vector<vector<ll>> &dp) {
  int w = _sqrt(n), h = (n - 1) / w + 1;
  printf("%d ", (w + h) * 2);
  ll ans = 0;
  for (int i = max(w - 100, 1); i <= (h + 100); i++)
    if (i + (n - 1) / i + 1 == w + h) {
      ans += res[i * ((n - 1) / i + 1) - n];
    }
  printf("%lld\n", ans % mod);
}
const int nn = 1500;
int main() {
  int tt, op;
  scanf("%d%d", &tt, &op);
  vector dp(nn, vector<ll>(nn, -1));
  if (op == 2) {
    scanf("%lld", &mod);
    res.resize(nn);
    for (int i = 0; i < nn; i++) res[i] = calc(i, i, dp);
    for (int i = 0; i < 2; i++) {
      res = mul(res, res);
      res.resize(nn);
    }
  }
  while (tt--) {
    int n;
    scanf("%d", &n);
    switch (op) {
      case 1:
        solve1(n);
        break;
      case 2:
        solve2(n, dp);
        break;
    }
  }
  return 0;
}