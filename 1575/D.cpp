#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int buff = 10;
char s[buff];
int dig(int a) { return a ? 1 + dig(a / 10) : 0; }
bool fit(int a, int n) {
  if (n > 1 && dig(a) != n) return false;
  int x = -1;
  for (int i = 0; s[i]; i++) {
    int t = a % 10;
    a /= 10;
    if (s[i] == '_') continue;
    if (s[i] == 'X') {
      if ((~x) && x != t) return false;
      x = t;
      continue;
    }
    if (s[i] - '0' != t) return false;
  }
  return !a;
}
int main() {
  scanf("%s", s);
  int n = strlen(s);
  reverse(s, s + n);
  int ans = 0;
  for (int i = 0; i < 1e8; i += 25)
    if (fit(i, n)) ans++;
  printf("%d\n", ans);
  return 0;
}