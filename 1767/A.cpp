#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    set<int> x, y;
    for (int i = 0; i < 3; i++) {
      int p, q;
      scanf("%d%d", &p, &q);
      x.insert(p);
      y.insert(q);
    }
    puts(x.size() == 3 || y.size() == 3 ? "YES" : "NO");
  }
  return 0;
}