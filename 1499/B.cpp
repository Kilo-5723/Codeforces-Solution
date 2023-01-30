#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int buff = 105;
char s[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    int n = strlen(s), a = n, b = -1;
    for (int i = n - 1; i; i--)
      if (s[i] == '1' && s[i - 1] == '1') a = i;
    for (int i = 1; i < n; i++)
      if (s[i] == '0' && s[i - 1] == '0') b = i;
    puts(a < b ? "NO" : "YES");
  }
  return 0;
}