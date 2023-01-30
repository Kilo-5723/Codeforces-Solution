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
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int x = n / 2 + 1, y = n / 2 + 1;
    int p;
    for (int i = 0; i < n; i++)
      if (a[i] == x) p = i;
    for (int i = p; i >= 0; i--)
      if (a[i] == x) x--;
    for (int i = p; i < n; i++)
      if (a[i] == y) y++;
    printf("%d\n", max(x, n - y + 1));
  }
  return 0;
}