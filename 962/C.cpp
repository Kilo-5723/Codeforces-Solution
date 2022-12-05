#include <cstdio>
#include <iostream>
using namespace std;
const int inf = 1e9;
int digit(int n) { return n ? digit(n / 10) + 1 : 0; }
int solve(int a, int b) {
  int res = digit(a) - digit(b);
  while (b) {
    while (a && a % 10 != b % 10) a /= 10;
    if (!a) return inf;
    a /= 10;
    b /= 10;
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  int ans = inf;
  for (int i = 1; i * i <= n; i++) ans = min(ans, solve(n, i * i));
  printf("%d\n", ans == inf ? -1 : ans);
  return 0;
}