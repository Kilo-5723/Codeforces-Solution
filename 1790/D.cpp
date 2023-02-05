#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      cnt[t]++;
    }
    int ans = 0;
    for (auto [k, v] : cnt)
      if (v && v > cnt[k + 1]) ans += v - cnt[k + 1];
    printf("%d\n", ans);
  }
  return 0;
}