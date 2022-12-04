#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &m, &n);
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    int ans = 1e9;
    for (int j = 0; j < n; j++) {
      int mxm = 0;
      for (int i = 0; i < m; i++) mxm = max(mxm, a[i][j]);
      // cout<<ans<<endl;
      ans = min(ans, mxm);
    }
    int mxm=0;
    for (int i = 0; i < m; i++) {
      sort(a[i].begin(), a[i].end());
      mxm = max(mxm, a[i][n - 2]);
    }
    printf("%d\n", min(ans,mxm));
  }
  return 0;
}