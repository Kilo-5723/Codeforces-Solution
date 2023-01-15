#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int k = 32;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector a(n, vector<int>());
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      a[i].resize(k);
      for (int j = 0; j < k; j++) {
        scanf("%d", &a[i][j]);
        cnt[a[i][j]]++;
      }
    }
    bool flg = false;
    for (int i = 0; i < n; i++) {
      bool res = true;
      for (auto v : a[i]) res = res && cnt[v] > 1;
      flg = flg || res;
    }
    puts(flg ? "YES" : "NO");
  }
  return 0;
}