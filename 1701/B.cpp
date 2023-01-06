#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    puts("2");
    for (int i = 1; i <= n; i += 2)
      for (int j = i; j <= n; j <<= 1) printf("%d ", j);
    puts("");
  }
  return 0;
}