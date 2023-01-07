#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef __int128 li;
const int inf = 1e9;
int maxdig(li n) { return n ? max((int)(n % 10), maxdig(n / 10)) : 0; }
int len(li n) { return n ? 1 + len(n / 10) : 0; }
int dfs(li x, int n, map<li, int> &dp) {
  if (len(x) >= n) return 0;
  if (dp.count(x)) return dp[x];
  int res = inf;
  for (li i = x; i; i /= 10)
    if (i % 10 > 1) res = min(res, dfs(i % 10 * x, n, dp) + 1);
  return dp[x] = res;
}
int main() {
  int n;
  li x;
  ll t;
  scanf("%d%lld", &n, &t);
  x = t;
  if (maxdig(x) == 1) {
    puts("-1");
    return 0;
  }
  map<li, int> dp;
  printf("%d\n", dfs(x, n, dp));
  return 0;
}