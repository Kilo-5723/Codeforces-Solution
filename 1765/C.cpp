#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n = 500;
  int ans = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k <= j; k++)
        if (n - i - j - k <= k) ans += (n - i - j - k);
  printf("%d\n", ans);
  return 0;
}