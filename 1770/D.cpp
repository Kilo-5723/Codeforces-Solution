#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int ff(vector<int> &f, int u) { return f[u] == u ? u : f[u] = ff(f, f[u]); }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    vector<int> f(n + 1), c(n + 1, 1), e(n + 1, 0), k(n + 1, 0);
    for (int i = 1; i <= n; i++) f[i] = i;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
      int u = ff(f, a[i]), v = ff(f, b[i]);
      if (u == v) {
        e[u]++;
        if (a[i] == b[i]) k[u] = 1;
        continue;
      }
      c[u] += c[v];
      e[u] += e[v] + 1;
      k[u] += k[v];
      f[v] = u;
    }
    for (int i = 1; i <= n; i++)
      if (f[i] == i) {
        if (c[i] != e[i]) {
          ans = 0;
          continue;
        }
        if (k[i])
          ans = ans * n % mod;
        else
          ans = ans * 2 % mod;
      }
    printf("%lld\n", ans);
  }
  return 0;
}