#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 5;
vector<ll> pow2_(maxn);
ll pow2(int n) {
  if (!n) return 1;
  return pow2_[n] = pow2(n - 1) * 2 % mod;
}
pair<ll, int> dfs(vector<vector<int>> &e, int u, int f) {
  ll res = 0;
  int d = 0;
  for (auto v : e[u])
    if (v != f) {
      auto [rv, dv] = dfs(e, v, u);
      res += rv;
      d = max(d, dv);
    }
  res += d + 1;
  return {res % mod, d + 1};
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<vector<int>> e(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    auto res = dfs(e, 1, 1);
    printf("%lld\n", res.first * pow2(n - 1) % mod);
  }
  return 0;
}