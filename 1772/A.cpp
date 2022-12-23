#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b;
    scanf("%d+%d", &a, &b);
    printf("%d\n", a + b);
  }
  return 0;
}