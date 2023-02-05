#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      sum += t;
    }
    printf("%d\n", sum == n ? n - 2 : sum + 2);
  }
  return 0;
}