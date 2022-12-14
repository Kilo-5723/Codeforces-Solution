#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int buff = 1e3;
char s[buff];
map<char, int> id = {{'.', 0}, {'m', 1}, {'#', 2}};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) a[i][j] = id[s[j]];
  }
  auto ps = a;
  for (auto &arr : ps)
    for (int i = 1; i < m; i++) arr[i] += arr[i - 1];
  int ans = 0;
  for (int i = 0; i < m; i++)
    for (int j = i + 2; j < m; j++) {
      int cnt1 = 0, cnt2 = 0;
      int sum1 = 0, sum2 = 0;
      for (int l = 0, r1 = 0, r2 = 0; l < n; l++) {
        while (r1 < n && sum1 + a[r1][i] + a[r1][j] < 1) {
          sum1 += a[r1][i] + a[r1][j];
          r1++;
          if (l < r1 - 2 && ps[r1 - 2][j - 1] - ps[r1 - 2][i] < 2) cnt1++;
        };
        while (r2 < n && sum2 + a[r2][i] + a[r2][j] < 2) {
          sum2 += a[r2][i] + a[r2][j];
          r2++;
          if (l < r2 - 2 && ps[r2 - 2][j - 1] - ps[r2 - 2][i] < 1) cnt2++;
        };
        if (cnt1) ans = max(ans, (r1 - l) * 2 + j - i - 1);
        if (cnt2) ans = max(ans, (r2 - l) * 2 + j - i - 1);
        sum1 -= a[l][i] + a[l][j];
        sum2 -= a[l][i] + a[l][j];
        if (l < r1 - 2 && ps[l + 1][j - 1] - ps[l + 1][i] < 2) cnt1--;
        if (l < r2 - 2 && ps[l + 1][j - 1] - ps[l + 1][i] < 1) cnt2--;
      }
    }
  printf("%d\n", ans);
  return 0;
}