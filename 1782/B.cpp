#include <algorithm>
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
    sort(a.begin(), a.end());
    // reverse(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i <= n; i++)
      ans += (i == 0 || i - 1 >= a[i - 1]) && (i == n || i < a[i]);
    printf("%d\n", ans);
  }
  return 0;
}