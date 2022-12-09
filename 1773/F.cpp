#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  vector<int> p(n), q(n);
  int k = 0;
  if (a > b) {
    while (k < n - 1 && b) {
      q[k++] = 1;
      b--;
    }
    while (k < n - 1 && a) {
      p[k++] = 1;
      a--;
    }
  } else {
    while (k < n - 1 && a) {
      p[k++] = 1;
      a--;
    }
    while (k < n - 1 && b) {
      q[k++] = 1;
      b--;
    }
  }
  p[n-1] = a;
  q[n-1] = b;
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (p[i] == q[i]) ans++;
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) printf("%d:%d\n", p[i], q[i]);
  return 0;
}