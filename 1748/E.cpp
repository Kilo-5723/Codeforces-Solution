#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct arr {
  vector<ll> a;
  int x;
};
vector<arr> stk;
arr add(arr aa, arr ab, int t) {
  auto a = aa.a;
  auto b = ab.a;
  for (int i = 1; i < b.size(); i++) b[i] = (b[i] + b[i - 1]) % mod;
  for (int i = 0; i < a.size(); i++) a[i] = (i < t ? 0 : b[i - t]) * a[i] % mod;
  return {a, max(aa.x, ab.x)};
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    stk = {};
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      arr tmp{vector<ll>(m, 1LL), t};
      while (stk.size() > 1 && stk[stk.size() - 2].x < t) {
        auto tmp = stk.back();
        stk.pop_back();
        stk.back() = add(stk.back(), tmp, 0);
      }
      if (stk.size() && t > stk.back().x)
        stk.back() = add(tmp, stk.back(), 1);
      else
        stk.push_back(tmp);
    }
    while (stk.size() > 1) {
      auto b = stk.back();
      stk.pop_back();
      stk.back() = add(stk.back(), b, 0);
    }
    ll ans = 0;
    for (auto v : stk[0].a) ans += v;
    printf("%lld\n", (ans % mod + mod) % mod);
  }
  return 0;
}