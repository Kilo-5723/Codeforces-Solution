#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a[3];
    for (int i = 0; i < 3; i++) scanf("%d", &a[i]);
    sort(a, a + 3);
    printf("%d\n", a[1]);
  }
  return 0;
}