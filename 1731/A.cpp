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
    ll mul = 1;
    for (int i = 0; i < n; i++) {
      ll t;
      scanf("%lld", &t);
      mul = mul * t;
    }
    printf("%lld\n", 2022 * (mul + n - 1));
  }
  return 0;
}