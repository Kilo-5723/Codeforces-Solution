#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  printf("%d\n", n * m + n + m - 3);
  for (int i = 1; i < m; i++) putchar('L');
  for (int i = 1; i < n; i++) putchar('U');
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) putchar(i & 1 ? 'L' : 'R');
    if (i < n - 1) putchar('D');
  }
  puts("");
  return 0;
}