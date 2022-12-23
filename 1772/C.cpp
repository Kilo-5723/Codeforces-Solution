#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &k, &n);
    set<int> sel;
    int j = 0;
    for (int i = 0; i < n && k; k--) {
      sel.insert(i);
      i += ++j;
    }
    j = n - 1;
    while (k--) {
      while (sel.count(j)) j--;
      sel.insert(j);
    }
    for (auto v : sel) printf("%d ", v + 1);
    puts("");
  }
  return 0;
}