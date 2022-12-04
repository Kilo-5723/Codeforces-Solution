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
    int p = 0;
    while (p < n - 1 && a[p] >= a[p + 1]) p++;
    while (p < n - 1 && a[p] <= a[p + 1]) p++;
    puts(p == n - 1 ? "YES" : "NO");
  }
  return 0;
}