#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k, m;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> a(m);
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    int x = n / k, y = n % k;
    bool flg = true;
    for (auto v : a) {
      if (v > x + 1) flg = false;
      if (v == x + 1) y--;
    }
    puts(flg && y >= 0 ? "YES" : "NO");
  }
  return 0;
}