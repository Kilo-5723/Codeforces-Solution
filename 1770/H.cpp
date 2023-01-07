#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> solve(vector<int> a) {
  int n = a.size();
  vector<vector<pair<int, int>>> res(n);
  for (int i = 0; i < n; i++) {
    for (int j = i; j; j--)
      if (a[j - 1] > a[j]) {
        res[a[j - 1]].push_back({i - j - 1, 1});
        res[a[j]].push_back({i - j, -1});
        cout << a[j - 1] << ' ' << i << ' ' << j << ' ' << i - j << ' ' << 1
             << endl;
        cout << a[j] << ' ' << i << ' ' << j << ' ' << i - j + 1 << ' ' << -1
             << endl;
        swap(a[i - 1], a[j]);
      }
  }
  return res;
}
vector<pair<int, int>> path(vector<pair<int, int>> a, int v, int n) {
  vector<pair<int, int>> res;
  reverse(a.begin(), a.end());
  for (int i = 0; i <= n; i++) {
    res.push_back({i, v});
    while (a.size() && i == a.back().second) {
      v += a.back().second;
      res.push_back({i, v});
      a.pop_back();
    }
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