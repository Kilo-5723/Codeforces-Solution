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
    vector<bool> vis(n + 1);
    int p = 0;
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      bool flg = false;
      while (k--) {
        int t;
        scanf("%d", &t);
        if (!flg && !vis[t]) {
          vis[t] = true;
          flg = true;
        }
      }
      if (!flg) p = i + 1;
    }
    if (!p) {
      puts("OPTIMAL");
      continue;
    }
    puts("IMPROVE");
    printf("%d ", p);
    for (int i = 1; i <= n; i++)
      if (!vis[i]) {
        printf("%d\n", i);
        break;
      }
  }
  return 0;
}