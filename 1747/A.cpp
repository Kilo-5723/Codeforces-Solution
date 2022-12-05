#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll ans = 0;
    while (n--) {
      int t;
      scanf("%d", &t);
      ans += t;
    }
    if (ans < 0) ans = -ans;
    printf("%lld\n", ans);
  }
  return 0;
}