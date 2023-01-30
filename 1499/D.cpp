#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 2e7 + 5;
vector<int> a(maxn);
ll calc2(int c, int d, int x) {
  if ((x + d) % c) return 0;
  ll k = (x + d) / c;
  return 1ll << a[k];
}
ll calc1(int c, int d, int x) {
  ll res = 0;
  for (int i = 1; i * i <= x; i++)
    if (!(x % i)) {
      res += calc2(c, d, i);
      if (i * i != x) res += calc2(c, d, x / i);
    }
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  for (int i = 2; i < maxn; i++)
    if (!a[i])
      for (int j = i; j < maxn; j += i) a[j]++;
  while (tt--) {
    int c, d, x;
    scanf("%d%d%d", &c, &d, &x);
    printf("%lld\n", calc1(c, d, x));
  }
  return 0;
}