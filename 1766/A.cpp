#include <cstdio>
#include <iostream>
using namespace std;
int solve(int n) {
  if (n < 10) return n;
  return 9 + solve(n / 10);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));
  }
  return 0;
}