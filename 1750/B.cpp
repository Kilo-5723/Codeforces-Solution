#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int tot[2];
    memset(tot, 0, sizeof(tot));
    int cur = 0, cnt = 0;
    ll mxm = 0;
    getchar();
    while (n--) {
      int t = getchar() - '0';
      tot[t]++;
      if (t == cur)
        cnt++;
      else {
        mxm = max(mxm, 1LL * cnt * cnt);
        cnt = 1;
        cur = t;
      }
    }
    mxm = max(mxm, 1LL * cnt * cnt);
    printf("%lld\n", max(mxm, 1LL * tot[0] * tot[1]));
  }
  return 0;
}