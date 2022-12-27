#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    if (n == 1) {
      puts("2");
      continue;
    }
    printf("%d\n", (n - 1) / 3 + 1);
  }
  return 0;
}