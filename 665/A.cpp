#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int a, ta;
  scanf("%d%d", &a, &ta);
  int b, tb;
  scanf("%d%d", &b, &tb);
  int hh, mm;
  scanf("%d:%d", &hh, &mm);
  mm += hh * 60 - 300;
  int l = mm - tb, r = mm + ta - 1;
  l = max(l, -1);
  r = min(r, 19 * 60 - 1);
  l -= (l % b + b) % b;
  r -= r % b;
  printf("%d\n", (r - l) / b);
  // int l = mm - tb + 1, r = mm + ta - 1;
  // int ans = 0;
  // for (int i = 300; i < 24 * 60; i += b)
  //   if (i >= l && i <= r) ans++;
  // cout << ans << endl;
  return 0;
}