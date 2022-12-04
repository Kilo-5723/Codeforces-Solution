#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    if (a[0] == a.back()) {
      printf("%d\n", n / 2);
      continue;
    }
    int k = n / 2, l = k, r = k;
    while (l >= 0 && a[l] == a[k]) l--;
    while (r < n && a[r] == a[k]) r++;
    l++;
    ll ans = max(1LL * l * (n - l), 1LL * r * (n - r));
    printf("%lld\n",ans);
  }
  return 0;
}