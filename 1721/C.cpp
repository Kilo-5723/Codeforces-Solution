#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    vector<int> d(n);
    for (int i = 0, p = 0; i < n; i++) {
      while (p < n && b[p] < a[i]) p++;
      d[i] = b[p] - a[i];
    }
    for (auto v : d) printf("%d ", v);
    puts("");
    for (int i = n - 1, p = n; i >= 0; i--) {
      d[i] = b[p - 1] - a[i];
      if (i && a[i] > b[i - 1]) p = i;
    }
    for (auto v : d) printf("%d ", v);
    puts("");
  }
  return 0;
}