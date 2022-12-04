#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int get_sum(const vector<int> &a) {
  int res = 0;
  for (auto v : a) res += v;
  return res;
}
struct opr {
  int a, b, c;
};
vector<opr> ans;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
      sum += get_sum(a[i]);
    }
    if (sum % n) {
      puts("-1");
      continue;
    }
    int avg = sum / n;
    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(),
         [&](int i, int j) { return get_sum(a[i]) < get_sum(a[j]); });
    int l = 0, r = n - 1;
    ans.clear();
    while (l < r) {
      auto &p = a[ord[l]], &q = a[ord[r]];
      int t = min(avg - get_sum(p), get_sum(q) - avg);
      for (int i = 0; i < m && t; i++)
        if (!p[i] && q[i]) {
          swap(p[i], q[i]);
          ans.push_back({ord[l] + 1, ord[r] + 1, i + 1});
          t--;
        }
      if (get_sum(p) == avg) l++;
      if (get_sum(q) == avg) r--;
    }
    printf("%lu\n", ans.size());
    for (const auto &[a, b, c] : ans) printf("%d %d %d\n", a, b, c);
  }
  return 0;
}