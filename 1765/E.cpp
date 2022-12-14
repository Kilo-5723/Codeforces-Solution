#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (b < a) {
      puts("1");
      continue;
    }
    printf("%d\n", (n - 1) / a + 1);
  }
  return 0;
}