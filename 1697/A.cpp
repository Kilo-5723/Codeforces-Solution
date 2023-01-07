#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      sum += t;
    }
    printf("%d\n", max(0, sum - m));
  }
  return 0;
}