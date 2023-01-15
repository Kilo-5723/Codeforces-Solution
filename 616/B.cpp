#include <cstdio>
#include <iostream>
using namespace std;
const int inf = 1e9;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int mxm = 0;
  for (int i = 0; i < n; i++) {
    int mnm = inf;
    for (int i = 0; i < m; i++) {
      int t;
      scanf("%d", &t);
      mnm = min(mnm, t);
    }
    mxm = max(mxm, mnm);
  }
  printf("%d\n", mxm);
  return 0;
}