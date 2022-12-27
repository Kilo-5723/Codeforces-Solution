#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
bool check(const vector<vector<bool>> &a, int i, int j) {
  for (auto [dx, dy] : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}})
    if (a[i + dx][j + dy] == a[i][j]) return false;
  return true;
}
int cnt(const vector<vector<bool>> &a) {
  int res = 0;
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < m - 1; j++) res += check(a, i, j);
  return res;
}
const int buff = 1e5;
char s[buff];
vector<vector<bool>> read() {
  vector<vector<bool>> res(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) res[i][j] = s[j] - '0';
  }
  return res;
}
struct operation {
  int a, b, c;
};
int main() {
  scanf("%d%d%d", &n, &m, &k);
  vector<vector<vector<bool>>> arr(k + 1);
  for (int i = 0; i <= k; i++) arr[i] = read();
  vector<int> ord(k + 1);
  for (int i = 0; i <= k; i++) ord[i] = i;
  sort(ord.begin(), ord.end(),
       [&](int i, int j) { return cnt(arr[i]) > cnt(arr[j]); });
  printf("%d\n", ord[0] + 1);
  vector<operation> ans;
  for (int t = 1; t <= k; t++) {
    auto a = arr[ord[t - 1]], b = arr[ord[t]];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] != b[i][j]) ans.push_back({1, i + 1, j + 1});
    ans.push_back({2, ord[t] + 1});
  }
  printf("%lu\n", ans.size());
  for (auto [a, b, c] : ans)
    if (a == 1)
      printf("%d %d %d\n", a, b, c);
    else
      printf("%d %d\n", a, b);
  return 0;
}