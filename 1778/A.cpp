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
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    int mxm = -2;
    for (int i = 1; i < n; i++) mxm = max(mxm, -a[i - 1] - a[i]);
    printf("%d\n", sum + 2 * mxm);
  }
  return 0;
}