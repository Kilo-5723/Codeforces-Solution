#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", (n + 1) / 2);
    for (int i = 0; i < n / 2; i++) printf("%d %d\n", 3 * i + 1, 3 * (n - i));
    if (n & 1) printf("%d %d\n", n / 2 * 3 + 1, n / 2 * 3 + 3);
  }
  return 0;
}