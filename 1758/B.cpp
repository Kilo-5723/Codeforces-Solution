#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    if (n & 1) {
      for (int i = 0; i < n; i++) printf("1 ");
      puts("");
    } else {
      for (int i = 2; i < n; i++) printf("2 ");
      printf("1 3\n");
    }
  }
  return 0;
}