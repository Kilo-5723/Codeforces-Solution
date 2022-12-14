#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n + 1, n);
    while (m--) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (x > y) swap(x, y);
      a[x] = min(a[x], y - 1);
    }
    for (int i = n - 1; i; i--) a[i] = min(a[i], a[i + 1]);
    ll ans = 0;
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    for (int i = 1; i <= n; i++) ans += a[i] - i + 1;
    printf("%lld\n", ans);
  }
  return 0;
}