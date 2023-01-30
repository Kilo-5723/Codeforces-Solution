#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
const int maxn = 1e5 + 5;
vector<vector<int>> divs(maxn);
void add(vector<int> &cnt, int &tot, int v) {
  for (auto d : divs[v])
    if (d < cnt.size() && !cnt[d]++) tot++;
}
void sub(vector<int> &cnt, int &tot, int v) {
  for (auto d : divs[v])
    if (d < cnt.size() && !--cnt[d]) tot--;
}
int main() {
  for (int i = 1; i < maxn; i++)
    for (int j = i; j < maxn; j += i) divs[j].push_back(i);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int ans = inf;
    vector<int> cnt(m + 1);
    int tot = 0;
    for (int l = 0, r = 0; true; l++) {
      while (r < n && tot < m) add(cnt, tot, a[r++]);
      if (tot < m) break;
      ans = min(ans, a[r - 1] - a[l]);
      sub(cnt, tot, a[l]);
    }
    printf("%d\n", ans < inf ? ans : -1);
  }
  return 0;
}