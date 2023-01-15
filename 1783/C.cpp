#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    auto b = a;
    sort(b.begin(), b.end());
    int win = 0, left = m;
    while (win < n && b[win] <= left) left -= b[win++];
    if (win == n) {
      printf("%d\n", 1);
      continue;
    }
    if (win == 0) {
      printf("%d\n", n + 1);
      continue;
    }
    if (left + b[win - 1] - a[win] >= 0)
      printf("%d\n", n - win);
    else
      printf("%d\n", n - win + 1);
  }
  return 0;
}