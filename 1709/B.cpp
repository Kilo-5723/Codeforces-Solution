#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll solve(const vector<ll> &a, int s, int t) { return a[t] - a[s]; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<ll> a(n);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  vector<ll> s1(n), s2(n);
  for (int i = 1; i < n; i++) s1[i] = s1[i - 1] + max(a[i - 1] - a[i], 0ll);
  reverse(a.begin(), a.end());
  for (int i = 1; i < n; i++) s2[i] = s2[i - 1] + max(a[i - 1] - a[i], 0ll);
  while (m--) {
    int s, t;
    scanf("%d%d", &s, &t);
    if (s < t)
      printf("%lld\n", solve(s1, s - 1, t - 1));
    else
      printf("%lld\n", solve(s2, n - s, n - t));
  }
  return 0;
}