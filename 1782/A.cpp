#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int inf = 1e9;
int solve(int w, int d, int h, int a, int b, int f, int g) {
  return a + f + abs(b - g) + h;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int w, d, h;
    scanf("%d%d%d", &w, &d, &h);
    int a, b, f, g;
    scanf("%d%d%d%d", &a, &b, &f, &g);
    int ans =
        min({solve(w, d, h, a, b, f, g), solve(w, d, h, w - a, b, w - f, g),
             solve(d, w, h, b, a, g, f), solve(d, w, h, d - b, a, d - g, f)});
    printf("%d\n", ans);
  }
  return 0;
}