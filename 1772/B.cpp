#include <cstdio>
#include <iostream>
using namespace std;
bool check(int a, int b, int c, int d) {
  return a < b && a < c && b < d && c < d;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    bool flg = check(a, b, c, d) || check(c, a, d, b) || check(d, c, b, a) ||
               check(b, d, a, c);
    puts(flg ? "YES" : "NO");
  }
  return 0;
}