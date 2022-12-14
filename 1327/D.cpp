#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int solve(const vector<int> &a, const vector<int> &c) {
  vector<int> d;
  int n = a.size();
  for (int i = 1; i * i <= n; i++)
    if (!(n % i)) {
      d.push_back(i);
      d.push_back(n / i);
    }
  sort(d.begin(), d.end());
  for (auto p : d) {
    for (int i = 0; i < p; i++) {
      bool flg = true;
      for (int j = i; j < a.size(); j += p)
        if (c[a[j]] != c[a[i]]) {
          flg = false;
          break;
        }
      if (flg) return p;
    }
  }
  return a.size();
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    int ans = n;
    for (int i = 1; i <= n; i++)
      if (a[i]) {
        vector<int> t = {i};
        for (int j = a[i]; j != i; j = a[j]) t.push_back(j);
        ans = min(ans, solve(t, c));
        for (auto v : t) a[v] = 0;
      }
    printf("%d\n", ans);
  }
  return 0;
}