#include <cstdio>
#include <iostream>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int mxm = 0, g = 0;
    while (n--) {
      int t;
      scanf("%d", &t);
      mxm = max(mxm, t);
      g = gcd(g, t);
    }
    printf("%d\n", mxm / g);
  }
  return 0;
}