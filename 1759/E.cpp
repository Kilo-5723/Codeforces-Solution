#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int solve(vector<ll> a, ll h, vector<int> v) {
  v.push_back(1);
  while (v.size()) {
    h *= v.back();
    v.pop_back();
    while (a.size() && h > a.back()) {
      // printf("%lld %lld\n",h,a.back());
      h += a.back() / 2;
      a.pop_back();
    }
  }
  // puts("");
  return a.size();
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    ll h;
    scanf("%d%lld", &n, &h);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = n;
    ans = min(ans, solve(a, h, {2, 2, 3}));
    ans = min(ans, solve(a, h, {2, 3, 2}));
    ans = min(ans, solve(a, h, {3, 2, 2}));
    printf("%d\n", n - ans);
  }
  return 0;
}