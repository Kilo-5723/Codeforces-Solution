#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, x;
    scanf("%d%d", &n, &x);
    if (n % x) {
      puts("-1");
      continue;
    }
    printf("%d ", x);
    for (int i = 2; i < n; i++) {
      if (i < x) {
        printf("%d ", i);
        continue;
      }
      for (int j = 2 * x; j <= n; j += x)
        if (!(n % j)) {
          x = j;
          printf("%d ", j);
          break;
        }
    }
    puts("1");
  }
  return 0;
}