#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d %d\n", n > 2 ? 2 : n, m > 2 ? 2 : m);
  }
  return 0;
}