#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    int t = 0;
    for (int i = k - 1; i < n; i += k) a[i] = ++t;
    // if (k == 1) {
    //   for (int i = 0; i < n; i++) printf("%d ", a[i]);
    //   puts("");
    //   continue;
    // }
    t = n;
    for (int i = 0; i < n; i++)
      if (!a[i]) a[i] = t--;
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
  }
  return 0;
}