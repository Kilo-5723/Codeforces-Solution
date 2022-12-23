#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int cnt1 = 0, cnt2 = 0;
    bool flg = false;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      bool b1 = t != i + 1, b2 = t != n - i;
      cnt1 += b1;
      cnt2 += b2;
      if (i + 1 == n - i) flg = t == (i + 1);
    }

    bool w1, w2;
    if (cnt1 * 2 - 1 + flg >= n)
      w1 = false;
    else
      w1 = cnt1 <= cnt2;
    if (cnt2 * 2 + flg >= n)
      w2 = false;
    else
      w2 = cnt2 < cnt1;
    puts(w1 ? "First" : w2 ? "Second" : "Tie");
  }
  return 0;
}