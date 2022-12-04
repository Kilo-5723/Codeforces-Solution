#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i * 2 < n - 1; i++) printf("%d %d ", 3 * n + i, 5 * n - i);
    if (n & 1)
      printf("%d\n", 4 * n);
    else
      puts("");
  }
  return 0;
}