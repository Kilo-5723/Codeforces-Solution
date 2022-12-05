#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    int c2 = 0, c5 = 0;
    while (n % 2 == 0) {
      n /= 2;
      c2++;
    }
    while (n % 5 == 0) {
      n /= 5;
      c5++;
    }
    while (c2 > c5 && m >= 5) {
      m /= 5;
      c5++;
    }
    while (c5 > c2 && m >= 2) {
      m /= 2;
      c2++;
    }
    while (m >= 10) {
      m /= 10;
      c2++;
      c5++;
    }
    n *= m;
    while (c2--) n *= 2;
    while (c5--) n *= 5;
    printf("%lld\n", n);
  }
  return 0;
}