#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 50;
char s[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int res = -1;
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      for (int j = 0; s[j]; j++)
        if (s[j] == 'R') {
          if (!~res) res = j;
          if (res > j) res = -2;
        }
    }
    puts(res < 0 ? "NO" : "YES");
  }
  return 0;
}