#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int ans = 0, cnt = 0;
    while (n--) {
      int t;
      scanf("%d", &t);
      if (t > 1)
        ans++;
      else
        cnt++;
    }
    ans += (cnt + 1) / 2;
    printf("%d\n", ans);
  }
  return 0;
}