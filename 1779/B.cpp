#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    if (n == 3) {
      puts("NO");
      continue;
    }
    puts("YES");
    if (n & 1) {
      for (int i = 1; i < n; i += 2) printf("%d %d ", n - 3, -n + 1);
      printf("%d\n", n - 3);
    } else {
      for (int i = 0; i < n; i += 2) printf("1 -1 ");
      puts("");
    }
  }
  return 0;
}