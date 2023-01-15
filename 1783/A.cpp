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
    if (a[0] == a.back()) {
      puts("NO");
      continue;
    }
    puts("YES");
    printf("%d", a.back());
    for (int i = 0; i < n - 1; i++) printf(" %d", a[i]);
    puts("");
  }
  return 0;
}