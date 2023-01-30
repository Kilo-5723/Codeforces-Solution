#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int buff = 1e6;
char s[buff];
ll solve(const vector<ll> &a, const char s[]) {
  ll cur = 0;
  for (int i = 0; s[i]; i++) cur += (s[i] == 'B') * a[i];
  ll res = cur;
  for (int i = 0; s[i]; i++) {
    cur += (s[i] == 'A' ? 1 : -1) * a[i];
    res = max(res, cur);
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  scanf("%s", s);
  ll ans = solve(a, s);
  reverse(a.begin(), a.end());
  reverse(s, s + strlen(s));
  ans = max(ans, solve(a, s));
  printf("%lld\n", ans);
  return 0;
}