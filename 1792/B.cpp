#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (!a) {
      puts("1");
      continue;
    }
    int ans = a, t = min(b, c);
    b -= t;
    c -= t;
    ans += 2 * t;
    int r1 = a, r2 = a;
    t = min(r1, b);
    ans += t;
    r2 += t;
    r1 -= t;
    b -= t;
    t = min(r2, c);
    ans += t;
    r1 += t;
    r2 -= t;
    c -= t;
    t = min({r1, r2, d});
    ans += t;
    r1 -= t;
    r2 -= t;
    d -= t;
    printf("%d\n", ans + (b || c || d));
  }
  return 0;
}