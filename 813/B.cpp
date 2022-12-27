#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef __int128 li;
int main() {
  ll x, y, l, r;
  scanf("%lld%lld%lld%lld", &x, &y, &l, &r);
  vector<ll> a, b;
  for (li i = 1; i <= r; i *= x) a.push_back(i);
  for (li i = 1; i <= r; i *= y) b.push_back(i);
  vector<ll> comb = {l - 1, r + 1};
  for (auto u : a)
    for (auto v : b)
      if (u + v >= l && u + v <= r) comb.push_back(u + v);
  sort(comb.begin(), comb.end());
  // for (auto v : comb) cout << v << ' ';
  // cout << endl;
  ll ans = 0;
  for (int i = 1; i < comb.size(); i++)
    ans = max(ans, comb[i] - comb[i - 1] - 1);
  printf("%lld\n", ans);
  return 0;
}