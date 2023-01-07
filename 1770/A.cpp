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
    vector<int> a(n + m);
    for (int i = 0; i < n + m; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end() - 1);
    ll ans = 0;
    for (int i = m; i < n + m; i++) ans += a[i];
    printf("%lld\n", ans);
  }
  return 0;
}