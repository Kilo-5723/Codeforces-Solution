#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool check(const vector<vector<int>> &a, int l) {
  // puts("1");
  vector s(a.size(), vector<int>(a[0].size() - l + 1));
  for (int i = 0; i < a.size(); i++) {
    // cout << i << endl;
    int cnt = 0;
    for (int j = 0; j < l; j++) cnt += a[i][j] < l;
    s[i][0] = !cnt;
    for (int j = 1; j + l <= a[0].size(); j++) {
      cnt -= a[i][j - 1] < l;
      cnt += a[i][j + l - 1] < l;
      s[i][j] = !cnt;
    }
    // for (int j = 0; j < s[i].size(); j++) cout << s[i][j] << ' ';
    // cout << endl;
  }
  // puts("1");
  for (int j = 0; j + l <= a[0].size(); j++) {
    int cnt = 0;
    for (int i = 0; i < l; i++) cnt += !s[i][j];
    if (!cnt) return true;
    for (int i = 1; i + l <= a.size(); i++) {
      cnt -= !s[i - 1][j];
      cnt += !s[i + l - 1][j];
      if (!cnt) return true;
    }
  }
  // printf("m :%d\n", l);
  return false;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    int l = 1, r = min(n, m) + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (check(a, m))
        l = m;
      else
        r = m;
    }
    printf("%d\n", l);
  }
  return 0;
}