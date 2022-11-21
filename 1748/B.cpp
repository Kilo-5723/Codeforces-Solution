#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn];
bool check(char s[], int n) {
  int cnt[10];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) cnt[s[i] - '0']++;
  int diff = 0;
  for (int i = 0; i < 10; i++)
    if (cnt[i]) diff++;
  for (int i = 0; i < 10; i++)
    if (cnt[i] > diff) return false;
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 1; j <= 100 && i + j <= n; j++) ans += check(s + i, j);
    printf("%d\n", ans);
  }
  return 0;
}