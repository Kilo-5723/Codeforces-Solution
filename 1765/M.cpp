#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    bool flg = false;
    for (int i = 2; i * i <= n; i++)
      if (!(n % i)) {
        printf("%d %d\n", n / i, n / i * (i - 1));
        flg = true;
        break;
      }
    if (!flg) printf("%d %d\n", 1, n - 1);
  }
  return 0;
}