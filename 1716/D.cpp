#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int mod = 998244353;
struct modnum {
  int n;
};
modnum operator+(modnum a, modnum b) {
  a.n += b.n;
  if (a.n >= mod) a.n -= mod;
  return a;
}
int main() {
  int k, n;
  scanf("%d%d", &n, &k);
  vector<modnum> a(n + 1), dp(n + 1);
  dp[0] = {1};
  for (int i = 0; i * i / 2 <= n; i++, k++) {
    vector<modnum> next(n + 1);
    for (int j = k; j <= n; j++) next[j] = next[j] + dp[j - k] + next[j - k];
    dp = next;
    for (int i = 0; i <= n; i++) a[i] = a[i] + dp[i];
  }
  a.erase(a.begin());
  for (auto v : a) printf("%d ", v);
  puts("");
  return 0;
}