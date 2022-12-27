#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int calc(int x, int y, int ax, int ay, int bx, int by) {
  if (ax + bx > x && ay + by > y) return 0;
  if (ax > x || bx > x || ay > y || by > y) return 0;
  return ax * ay + bx * by;
}
int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  int ans = 0;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      ans = max(ans,
                calc(x, y, a[i].first, a[i].second, a[j].first, a[j].second));
      ans = max(ans,
                calc(x, y, a[i].second, a[i].first, a[j].first, a[j].second));
      ans = max(ans,
                calc(x, y, a[i].first, a[i].second, a[j].second, a[j].first));
      ans = max(ans,
                calc(x, y, a[i].second, a[i].first, a[j].second, a[j].first));
    }
  printf("%d\n", ans);
  return 0;
}