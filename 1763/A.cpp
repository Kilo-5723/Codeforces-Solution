#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int mxm = 0, mnm = (1 << 20) - 1;
    while (n--) {
      int t;
      scanf("%d", &t);
      mnm &= t;
      mxm |= t;
    }
    printf("%d\n", mxm - mnm);
  }
  return 0;
}