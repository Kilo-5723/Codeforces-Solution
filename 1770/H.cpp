#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> solve(vector<int> a) {
  int n = a.size();
  vector<vector<pair<int, int>>> res(n);
  vector<int> ord;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] < i) {
      ord.push_back(i);
      for (int p = ord.size() - 1; p; p--)
        if (a[ord[p]] < a[ord[p - 1]]) swap(ord[p], ord[p - 1]);
      continue;
    }
    for (auto j : ord) {
      if (a[j] == j) continue;
      if (a[i] == i) break;
      // for (int k = i, j = i + 1; a[i] > i && j < n; j++)
      int p = 0;
      if (res[j].size()) p = max(p, res[j].back().first);
      if (res[i].size()) p = max(p, res[i].back().first);
      res[j].push_back({p, a[i] - a[j]});
      res[i].push_back({p + 1, a[j] - a[i]});
      swap(a[j], a[i]);
    }
  }
  return res;
}
vector<pair<int, int>> path(vector<pair<int, int>> a, int v, int n) {
  vector<pair<int, int>> res;
  reverse(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    while (a.size() && i == a.back().second) {
      v += a.back().second;
      res.push_back({i, v});
      a.pop_back();
    }
    res.push_back({i, v});
  }
  return res;
}
void write(vector<vector<pair<int, int>>> arr, vector<int> a, bool flg) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    auto p = path(arr[a[i]], i, n);
    if (flg)
      for (auto &[x, y] : p) swap(x, y);
    printf("%lu", p.size());
    for (auto [x, y] : p) printf(" %d %d", x + 1, y + 1);
    puts("");
  }
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (auto &v : a) v--;
  auto res = solve(a);
  write(res, a, false);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (auto &v : a) v--;
  res = solve(a);
  write(res, a, true);
  return 0;
}