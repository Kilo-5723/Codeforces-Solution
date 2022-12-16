#include <cstdio>
#include <iostream>
using namespace std;
int solve(int n) { return n ? solve(n / 2) * 2 : 1; }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
      int t;
      scanf("%d", &t);
      printf("%d %d\n", i, solve(t) - t);
    }
  }
  return 0;
}