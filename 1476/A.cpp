#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    k = ((n - 1) / k + 1) * k;
    printf("%d\n", ((k - 1) / n) + 1);
  }
  return 0;
}