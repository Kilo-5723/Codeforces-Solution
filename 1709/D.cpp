#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int query(const vector<vector<int>> &st, const vector<int> &log2, int l,
          int r) {
  if (r < l) swap(l, r);
  int k = log2[r - l + 1];
  return max(st[l][k], st[r - (1 << k) + 1][k]);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(m);
  for (int i = 0; i < m; i++) scanf("%d", &a[i]);
  vector<int> log2(m + 1);
  for (int i = 2; i <= m; i++) log2[i] = log2[i >> 1] + 1;
  vector<vector<int>> st(m);
  for (int i = 0; i < m; i++) st[i].push_back(a[i]);
  for (int i = 1; i <= log2[m]; i++)
    for (int j = 0; j + (1 << i) <= m; j++)
      st[j].push_back(max(st[j][i - 1], st[j + (1 << i - 1)][i - 1]));
  int q;
  scanf("%d", &q);
  while (q--) {
    int xs, ys, xt, yt, k;
    scanf("%d%d%d%d%d", &xs, &ys, &xt, &yt, &k);
    if ((xs - xt) % k || (ys - yt) % k) {
      puts("NO");
      continue;
    }
    int h = n - (n - xs) % k;
    // cout << h << endl;
    puts(query(st, log2, ys - 1, yt - 1) < h ? "YES" : "NO");
  }
  return 0;
}