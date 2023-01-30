#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  while (n--) {
    int t;
    scanf("%d", &t);
    ans += abs(t);
  }
  printf("%d\n", ans);
  return 0;
}