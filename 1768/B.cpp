#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = n;
    int c = 1;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      if (t == c) {
        c++;
        ans--;
      }
    }
    printf("%d\n", (ans + k - 1) / k);
  }
  return 0;
}