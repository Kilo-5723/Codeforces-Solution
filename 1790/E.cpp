#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    if ((n & 1) || (n & (n >> 1))) {
      puts("-1");
      continue;
    }
    n /= 2;
    printf("%d %d\n", n * 3, n);
  }
  return 0;
}