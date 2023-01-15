#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int al = 0, ar = 0;
  map<int, int> cnt;
  for (int l = 0, r = 0; r < n; l++) {
    while (r < n && cnt.size() < k) cnt[a[r++]]++;
    while (r < n && cnt.count(a[r])) cnt[a[r++]]++;
    if (r - l > ar - al) {
      al = l;
      ar = r;
    }
    if (!--cnt[a[l]]) cnt.erase(a[l]);
  }
  printf("%d %d\n", al + 1, ar);
  return 0;
}