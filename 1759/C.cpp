#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == b) {
      puts("0");
      continue;
    }
    if (b - a >= x || a - b >= x) {
      puts("1");
      continue;
    }
    if (a - l >= x && b - l >= x) {
      puts("2");
      continue;
    }
    if (r - a >= x && r - b >= x) {
      puts("2");
      continue;
    }
    if (a - l >= x && r - b >= x) {
      puts("3");
      continue;
    }
    if (r - a >= x && b - l >= x) {
      puts("3");
      continue;
    }
    puts("-1");
  }
  return 0;
}