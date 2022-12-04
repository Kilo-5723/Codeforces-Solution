#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 2e5 + 5;
char s[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    n--;
    scanf("%s", s);
    int las = 0, cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] - '0' == las)
        cnt++;
      else {
        sum += cnt;
        cnt = 1;
        las = s[i] - '0';
      }
      printf("%d ", sum + 1);  // sum[!(s[i] - '0')] + 1);
    }
    puts("");
  }
  return 0;
}