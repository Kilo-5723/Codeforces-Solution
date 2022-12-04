#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int drop(vector<vector<int>> &a, int x, int y) {
  if (x == a.size()) return y + 1;
  int t = a[x][y];
  a[x][y] = 2;
  switch (t) {
    case 1:
      return drop(a, x, y + 1);
    case 2:
      return drop(a, x + 1, y);
    case 3:
      return drop(a, x, y - 1);
  }
  return -1;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  while (k--) {
    int t;
    scanf("%d", &t);
    printf("%d ", drop(a, 0, t - 1));
  }
  puts("");
  return 0;
}