#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
vector<ll> dfs(int u, int f, vector<vector<int>> &e, int k) {
  vector<vector<ll>> que;
  for (auto v : e[u])
    if (v != f) que.push_back(dfs(v, u, e, k));
  for (int i = 0; i < que.size(); i++)
    if (que[i].size() > que.back().size()) swap(que[i], que.back());
  
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d", &n);
    vector<vector<int>> e(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    auto arr = dfs(1, 1, e, k);
    ll ans = -arr[0];
    for (auto v : arr) ans += v;
    printf("%lld\n", ans % mod);
  }
  return 0;
}