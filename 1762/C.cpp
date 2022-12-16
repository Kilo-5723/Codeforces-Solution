#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int buff = 2e5 + 5;
char s[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    ll ans = 0, mul = 0;
    char last = '$';
    for (int i = 0; s[i]; i++) {
      if (s[i] != last) {
        ans += mul;
        mul = 1;
        last = s[i];
        continue;
      }
      mul = (mul * 2 + 1) % mod;
    }
    ans += mul;
    printf("%lld\n", ans % mod);
  }
  return 0;
}