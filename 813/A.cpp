#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxm = 1e3 + 5;
int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  while (n--) {
    int t;
    scanf("%d", &t);
    sum += t;
  }
  int ans = -1;
  int m;
  scanf("%d", &m);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (!~ans && r >= sum) ans = max(sum, l);
  }
  printf("%d\n", ans);
  return 0;
}