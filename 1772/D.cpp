#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int mxm = inf, mnm = -inf;
    for (int i = 1; i < n; i++)
      if (a[i - 1] < a[i]) mxm = min(mxm, a[i - 1] + (a[i] - a[i - 1]) / 2);
    for (int i = 1; i < n; i++)
      if (a[i - 1] > a[i]) mnm = max(mnm, a[i] + (a[i - 1] - a[i] + 1) / 2);
    if (mxm < mnm)
      puts("-1");
    else
      printf("%d\n", mxm);
  }
  return 0;
}