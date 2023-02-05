#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 5;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (auto &v : a) scanf("%d", &v);
    sort(a.begin(), a.end());
    for (int i = 0; i + 1 < a.size(); i++) {
      if (a[i] + a[i + 1] < 0) {
        a[i] *= -1;
        a[i + 1] *= -1;
      }
    }
    ll ans = 0;
    for (auto v : a) ans += v;
    printf("%lld\n", ans);
  }
  return 0;
}