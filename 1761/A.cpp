#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a == n && b == n || a + b < n - 1)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}