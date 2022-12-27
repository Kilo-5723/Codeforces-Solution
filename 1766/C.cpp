#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 2e5 + 5;
char s[2][buff];
bool check(bool x, int p) {
  if (!s[x][p]) return true;
  if (s[x][p] == 'W') return false;
  if (s[!x][p] == 'B') x = !x;
  return check(x, p + 1);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s[0]);
    scanf("%s", s[1]);
    puts(check(0, 0) || check(1, 0) ? "YES" : "NO");
  }
  return 0;
}
