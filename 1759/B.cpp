#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int m, s;
    scanf("%d%d", &m, &s);
    int mxm = 0;
    for (int i = 0; i < m; i++) {
      int t;
      scanf("%d", &t);
      s += t;
      mxm = max(mxm, t);
    }
    bool flg = false;
    for (int i = mxm; i <= 100 && !flg; i++) flg = i * (i + 1) / 2 == s;
    puts(flg ? "YES" : "NO");
  }
  return 0;
}