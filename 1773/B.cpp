#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<bool> vis;
bool check1(int k, const vector<int> &arr, int l, int r) {
  // if (l==4&&r==5) cout<<"check "<<l<<' '<<r<<' '<<k<<endl;
  // cout << k << ' ' << l << ' ' << r << endl;
  for (int i = l; i < k; i++)
    if (vis[arr[i]]) return false;
  for (int i = k + 1; i < r; i++)
    if (!vis[arr[i]]) return false;
  // if (l==4&&r==5) puts("1");
  return true;
}
bool check2(int k, const vector<int> &arr, int l, int r) {
  // cout << k << ' ' << l << ' ' << r << endl;
  k = r + l - k - 1;
  // cout << k << ' ' << l << ' ' << r << endl;
  for (int i = l; i < k; i++)
    if (!vis[arr[i]]) return false;
  for (int i = k + 1; i < r; i++)
    if (vis[arr[i]]) return false;
  return true;
}
// bool check(int u, vector<vector<int>> &a, int l, int r) {
//   int k = -1;
//   for (int i = l; i <= r; i++)
//     if (a[0][i] == u) k = i;
//   for (const auto &arr : a) {
//     if (arr[k] != u && arr[r + l - k - 1]) return false;
//   }
//   for (int i = l; i < k; i++) vis[a[0][i]] = false;
//   for (int i = k + 1; i < r; i++) vis[a[0][i]] = true;
//   for (const auto &arr : a)
//     if (!check1(k, arr, l, r) && !check2(k, arr, l, r)) return false;
//   return true;
// }
bool check(int u, vector<vector<int>> &a, int l, int r) {
  // if (l == 4 && r == 5) {
  //   for (const auto &arr : a) cout << arr[l] << endl;
  //   cout << endl;
  // }
  int k = -1;
  for (int i = l; i < r; i++)
    if (a[0][i] == u) k = i;
  for (const auto &arr : a) {
    if (arr[k] != u && arr[r + l - k - 1] != u) return false;
  }
  for (int i = l; i < k; i++) vis[a[0][i]] = false;
  for (int i = k + 1; i < r; i++) vis[a[0][i]] = true;
  for (const auto &arr : a){
    // if (l==4&&r==5) cout<<"check "<<k<<' '<<u<<endl;
    if (!check1(k, arr, l, r) && !check2(k, arr, l, r)) return false;
  }
  return true;
}
int split(int u, vector<vector<int>> &a, int l, int r) {
  int k = -1;
  for (int i = l; i < r; i++)
    if (a[0][i] == u) k = i;
  for (int i = l; i < k; i++) vis[a[0][i]] = false;
  for (int i = k + 1; i < r; i++) vis[a[0][i]] = true;
  for (auto &arr : a)
    if (check2(k, arr, l, r)) reverse(arr.begin() + l, arr.begin() + r);
  return k;
}
void solve(vector<vector<int>> &a, vector<int> &p, int l, int r, int f) {
  // printf("%d %d %d\n", l, r, f);
  if (l >= r) return;
  // for (auto v : a[0])
  int v;
  for (int i = l + 1; i < r - 1; i++) {
    v = a[0][i];
    // cout << v << endl;
    if (!check(v, a, l, r)) continue;
    p[v] = f;
    int k = split(v, a, l, r);
    // printf("%d %d\n", v, k);
    solve(a, p, l, k, v);
    solve(a, p, k + 1, r, v);
    return;
  }
  if (check(v = a[0][l], a, l, r)) {
    p[v] = f;
    int k = split(v, a, l, r);
    // printf("%d %d\n", v, k);
    solve(a, p, l, k, v);
    solve(a, p, k + 1, r, v);
    return;
  }
  if (check(v = a[0][r - 1], a, l, r)) {
    p[v] = f;
    int k = split(v, a, l, r);
    // printf("%d %d\n", v, k);
    solve(a, p, l, k, v);
    solve(a, p, k + 1, r, v);
    return;
  }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<vector<int>> a(k, vector<int>(n));
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  vector<int> p(n + 1);
  vis.assign(n + 1, false);
  solve(a, p, 0, n, -1);
  for (int i = 1; i <= n; i++) printf("%d ", p[i]);
  puts("");
  return 0;
}