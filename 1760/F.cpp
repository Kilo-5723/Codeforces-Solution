#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
bool check(const vector<ll> &s, ll c, int d, int k) {
  int r = d / k, l = d % k;
  if (k >= s.size()) k = s.size() - 1;
  if (l >= s.size()) l = s.size() - 1;
  return r * s[k] + s[l] >= c;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, d;
    ll c;
    scanf("%d%lld%d", &n, &c, &d);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<ll> s(n + 1);
    for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
    int ans = 0;
    for (int i = 1; i <= d; i++)
      if (check(s, c, d, i)) ans = i;
    if (ans == 0)
      puts("Impossible");
    else if (ans == d)
      puts("Infinity");
    else
      printf("%d\n", ans - 1);
  }
  return 0;
}