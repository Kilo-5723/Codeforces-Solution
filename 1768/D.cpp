#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool conn(const vector<int> &a) {
  int las = -2;
  for (auto v : a)
    if (v == las + 1)
      return true;
    else
      las = v;
  return false;
}
void dfs(int u, vector<int> &a, vector<bool> &vis, vector<int> &arr) {
  if (vis[u]) return;
  arr.push_back(u);
  vis[u] = true;
  dfs(a[u], a, vis, arr);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (auto &v : a) v--;
    bool flg = false;
    int ans = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
      if (!vis[i]) {
        vector<int> arr;
        dfs(i, a, vis, arr);
        sort(arr.begin(), arr.end());
        // for (auto v : arr) cout << v << ' ';
        // cout << endl;
        flg = flg || conn(arr);
        ans++;
      }
    // cout << flg << endl;
    printf("%d\n", n - ans + (flg ? -1 : 1));
  }
  return 0;
}