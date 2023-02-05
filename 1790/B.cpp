#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, s, r;
    scanf("%d%d%d", &n, &s, &r);
    r = s - r - 1;
    s -= n;
    for (int i = 0; i < n; i++)
      if (s >= r) {
        printf("%d ", r + 1);
        s -= r;
      } else {
        printf("%d ", s + 1);
        s = 0;
      }
    puts("");
  }
  return 0;
}