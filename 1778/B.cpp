#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      p[t] = i;
    }
    vector<int> a(m);
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    int ans = inf;
    for (int i = 1; i < m; i++)
      ans = min({ans, p[a[i]] - p[a[i - 1]],
                 d < n - 1 ? d + 1 - p[a[i]] + p[a[i - 1]] : inf});
    printf("%d\n", max(ans, 0));
  }
  return 0;
}