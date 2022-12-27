#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m, x, y, d;
    scanf("%d%d%d%d%d", &n, &m, &x, &y, &d);
    printf("%d\n", (x - 1 > d && m - y > d) || (n - x > d && y - 1 > d)
                       ? n + m - 2
                       : -1);
  }
  return 0;
}