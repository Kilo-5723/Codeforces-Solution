#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int inf = 1e9;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int mxm = -inf, mnm = inf, cmx = 0, cmn = 0;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      if (t > mxm) {
        mxm = t;
        cmx = 0;
      }
      if (t < mnm) {
        mnm = t;
        cmn = 0;
      }
      if (t == mxm) cmx++;
      if (t == mnm) cmn++;
    }
    if (mxm != mnm)
      printf("%lld\n", (ll)2 * cmx * cmn);
    else
      printf("%lld\n", (ll)n * (n - 1));
  }
  return 0;
}