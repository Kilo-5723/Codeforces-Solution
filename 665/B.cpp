#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> a(k);
  for (int i = 0; i < k; i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int t;
      scanf("%d", &t);
      for (int i = k - 1; i; i--)
        if (a[i] == t) {
          swap(a[i], a[i - 1]);
          ans++;
        }
    }
  printf("%d\n", ans + n * m);
  return 0;
}