#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    set<int> sp, sq;
    for (int i = 1; i <= n; i++) sp.insert(i);
    sq = sp;
    vector<int> p(n), q(n);
    bool flg = true;
    for (int i = 0; i < n; i++) {
      if (sp.count(a[i])) {
        sp.erase(a[i]);
        p[i] = a[i];
        continue;
      }
      if (sq.count(a[i])) {
        sq.erase(a[i]);
        q[i] = a[i];
        continue;
      }
      flg = false;
      break;
    }
    if (!flg) {
      puts("NO");
      continue;
    }
    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] > a[j]; });
    for (auto u : ord) {
      if (p[u]) {
        if (*sq.rbegin() > a[u]) {
          flg = false;
          break;
        }
        q[u] = *sq.rbegin();
        sq.erase(*sq.rbegin());
      } else {
        if (*sp.rbegin() > a[u]) {
          flg = false;
          break;
        }
        p[u] = *sp.rbegin();
        sp.erase(*sp.rbegin());
      }
    }
    if (!flg) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    puts("");
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    puts("");
  }
  return 0;
}