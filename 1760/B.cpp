#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 105;
char s[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, s[i] - 'a');
    printf("%d\n", ans+1);
  }
  return 0;
}