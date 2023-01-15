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
    vector<int> a(n * n);
    for (int i = 0, v = 1; i < n * n; i += 2, v++) a[i] = v;
    for (int i = 1, v = n * n; i < n * n; i += 2, v--) a[i] = v;
    for (int i = 0; i < n; i++) {
      if (i & 1)
        for (int j = 0; j < n; j++) printf("%d ", a[i * n + j]);
      else
        for (int j = n - 1; j >= 0; j--) printf("%d ", a[i * n + j]);
      puts("");
    }
  }
  return 0;
}