#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool check(int ans, vector<int> p, vector<int> q) {
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  reverse(q.begin(), q.end());
  for (int i = 0; i < p.size(); i++)
    if (p[i] + q[i] != ans) return false;
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
      vector<int> p(n), q(n);
      ans += 1 << i;
      for (int j = 0; j < n; j++) p[j] = (a[j] & ans) >> i;
      for (int j = 0; j < n; j++) q[j] = (b[j] & ans) >> i;
      if (!check(ans >> i, p, q)) ans -= 1 << i;
    }
    printf("%d\n", ans);
  }
  return 0;
}