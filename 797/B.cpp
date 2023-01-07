#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  int mnm = inf;
  int mxm = -inf;
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if (t >= 0) {
      if (t & 1) mnm = min(mnm, t);
      sum += t;
    } else {
      if (t & 1) mxm = max(mxm, t);
    }
  }
  if (!(sum & 1)) sum -= min(mnm, -mxm);
  printf("%d\n", sum);
  return 0;
}