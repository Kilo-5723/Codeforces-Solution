#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
struct range {
  int l, r, v;
};
ll solve(int n, const vector<range>& arr) {
  vector<int> a(n + 2);
  vector<int> b(n + 1, 0);
  for (auto [l, r, v] : arr)
    if (v) {
      a[l]++;
      a[r + 1]--;
    } else {
      b[r] = max(b[r], l);
    }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    b[i] = max(b[i], b[i - 1]);
  }
  vector<ll> dp(n + 1);
  dp[0] = 1;
  ll sum = 0;
  for (int r = 1, l = 0; r <= n; r++)
    if (!a[r]) {
      while (l < b[r]) {
      }
    }
}
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  vector a(k, vector<range>(m));
  for (int i = 0; i < m; i++) {
    int l, r, v;
    scanf("%d%d%d", &l, &r, &v);
    for (int j = 0; j < k; j++) a[j][i] = {l, r, v >> j & 1};
  }
  ll ans = 1;
  for (const auto& arr : a) ans = ans * solve(n, arr) % mod;
  printf("%lld\n", ans);
  return 0;
}
