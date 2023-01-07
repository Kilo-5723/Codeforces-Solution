#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a = 0;
    while (n--) {
      int t;
      scanf("%d", &t);
      a = max(a, t);
    }
    int m;
    scanf("%d", &m);
    int b = 0;
    while (m--) {
      int t;
      scanf("%d", &t);
      b = max(b, t);
    }
    puts(a < b ? "Bob" : "Alice");
    puts(a <= b ? "Bob" : "Alice");
  }
  return 0;
}