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
    int p = 0;
    int m;
    scanf("%d", &m);
    while (m--) {
      int t;
      scanf("%d", &t);
      p = (p + t) % n;
    }
    printf("%d\n", a[p]);
  }
  return 0;
}