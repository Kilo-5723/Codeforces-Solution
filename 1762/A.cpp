#include <cstdio>
#include <iostream>
using namespace std;
const int inf = 1e9;
int opr1(int n) { return (n & 1) ? 1 + opr1(n / 2) : 0; }
int opr2(int n) { return (n & 1) ? 0 : 1 + opr2(n / 2); }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int ans = inf, sum = 0;
    while (n--) {
      int t;
      scanf("%d", &t);
      if (t & 1)
        ans = min(ans, opr1(t));
      else
        ans = min(ans, opr2(t));
      sum += t;
    }
    printf("%d\n", (sum & 1) ? ans : 0);
  }
  return 0;
}