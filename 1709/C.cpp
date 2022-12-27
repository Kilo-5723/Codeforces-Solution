#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int buff = 3e5;
char s[buff];
bool check(char s[]) {
  int cnt = 0;
  for (int i = 0; s[i]; i++)
    if (s[i] == '(')
      cnt++;
    else if (--cnt < 0)
      return false;
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    int n = strlen(s);
    int cl = n / 2, cr = n / 2;
    for (int i = 0; s[i]; i++) switch (s[i]) {
        case '(':
          cl--;
          break;
        case ')':
          cr--;
          break;
      }
    if (!cl || !cr) {
      puts("YES");
      continue;
    }
    bool flg = true;
    for (int i = 0; s[i]; i++)
      if (s[i] == '?') {
        if (cl > 1) {
          s[i] = '(';
          cl--;
          continue;
        }
        if (!cl) {
          s[i] = ')';
          cr--;
          continue;
        }
        if (!flg) {
          s[i] = '(';
          cl--;
          continue;
        }
        s[i] = ')';
        cr--;
        flg = false;
      }
    puts(check(s) ? "NO" : "YES");
  }
  return 0;
}