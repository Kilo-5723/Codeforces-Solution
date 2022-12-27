#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int inf = 1.5e9;
int solve(vector<vector<int>> a) {
  int n = a[0].size();
  multiset<int> st;
  int res = inf;
  for (int i = 0; i < n; i++) st.insert(a[0][i] - i + 1);
  for (int i = 0; i < n; i++) st.insert(a[1][i] - 2 * n + i + 2);
  res = min(res, *st.rbegin());
  int mxm = 0;
  for (int i = 2; i < n; i += 2) {
    mxm = max(mxm, a[0][i - 2] - 2 * i + 5);
    mxm = max(mxm, a[1][i - 2] - 2 * i + 4);
    mxm = max(mxm, a[1][i - 1] - 2 * i + 3);
    mxm = max(mxm, a[0][i - 1] - 2 * i + 2);
    st.erase(st.find(a[0][i - 2] - i + 2 + 1));
    st.erase(st.find(a[1][i - 2] - 2 * n + i - 2 + 2));
    st.erase(st.find(a[0][i - 1] - i + 1 + 1));
    st.erase(st.find(a[1][i - 1] - 2 * n + i - 1 + 2));
    res = min(res, max(mxm, *st.rbegin() - i));
  }
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    a[0][0] = -1;
    int ans = solve(a);
    int tmp = 0;
    tmp = max(tmp, a[1][0]);
    swap(a[0], a[1]);
    a[0].erase(a[0].begin());
    a[1].erase(a[1].begin());
    for (auto &v : a[0]) v -= 2;
    for (auto &v : a[1]) v -= 2;
    ans = min(ans, max(tmp, solve(a)));
    printf("%d\n", ans + 2 * n - 1);
  }
  return 0;
}