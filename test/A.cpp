#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 105;
char s[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (i) putchar(cnt ? '-' : '+');
      cnt += (cnt ? -1 : 1) * (s[i] - '0');
    }
    puts("");
  }
  return 0;
}