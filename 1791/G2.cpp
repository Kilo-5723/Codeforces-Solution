#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int solve(vector<ll> &arr, int p, int v, int c) {
  int l = -1, r = arr.size();
  while (r - l > 1) {
    int m = (l + r) / 2;
    int t = c;
    if (m > p) t += v;
    if (t < arr[m])
      r = m;
    else
      l = m;
  }
  if (l < p) l++;
  return l;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, c;
    scanf("%d%d", &n, &c);
    vector<int> a(n), b(n);
    vector<int> ord(n), pos(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      b[i] = a[i] + min(i + 1, n - i);
    }
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i, int j) { return b[i] < b[j]; });
    for (int i = 0; i < n; i++) pos[ord[i]] = i;
    vector<ll> arr(n + 1);
    for (int i = 0; i < n; i++) arr[i + 1] += arr[i] + b[ord[i]];
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (c >= a[i] + i + 1)
        ans = max(ans, solve(arr, pos[i], b[i], c - a[i] - i - 1));
    printf("%d\n", ans);
  }
  return 0;
}