#include <cstdio>
#include <iostream>
using namespace std;
bool check(int a, int b, int c) {
  c *= 2;
  c -= a + b;
  return c <= 0;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k1, k2;
    scanf("%d%d%d", &n, &k1, &k2);
    int w, b;
    scanf("%d%d", &w, &b);
    puts(check(k1, k2, w) && check(n - k1, n - k2, b) ? "YES" : "NO");
  }
  return 0;
}