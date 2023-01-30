#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 2e18;
int lim = 1e5;
vector<int> p;
void init(int n, int m1, int m2) {
  vector<pair<int, int>> a;
  p.clear();
  for (int i = 2; i < lim; i++) {
    int cnt = 0;
    while (!(m1 % i)) {
      cnt++;
      m1 /= i;
    }
    while (!(m2 % i)) {
      cnt++;
      m2 /= i;
    }
    if (cnt) p.push_back(i);
  }
  if (m1 != 1) p.push_back(m1);
  if (m2 != 1) p.push_back(m2);
  reverse(p.begin(), p.end());
}
vector<int> decomp(ll n) {
  vector<int> a(p.size(), 0);
  for (int i = 0; i < p.size(); i++)
    while (!(n % p[i])) {
      n /= p[i];
      a[i]++;
    }
  return a;
}
vector<ll> res;
void divs(vector<int> a, ll lim) {
  res.clear();
  res.push_back(1);
  for (int i = 0; i < a.size(); i++) {
    ll mul = 1;
    int n = res.size();
    for (int j = 0; j < a[i]; j++) {
      mul *= p[i];
      for (int k = 0; k < n; k++)
        if (res[k] * mul <= lim) res.push_back(res[k] * mul);
    }
  }
}
unordered_map<ll, int> arr;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m1, m2;
    scanf("%d%d%d", &n, &m1, &m2);
    init(n, m1, m2);
    auto arr = decomp(1ll * m1 * m2);
    divs(arr, n);
    auto d = res;
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    divs(arr, 2e18);
    auto a = res;
    int cnt = 0, tot = 0;
    for (auto v : a) {
      if (v <= n) {
        cnt++;
        tot ^= 1;
        continue;
      }
      for (auto k : d) {
        if (v / k > n) break;
        if (!(v % k)) {
          cnt++;
          tot ^= (v / k);
          break;
        }
      }
    }
    printf("%d %d\n", cnt, tot);
  }
  return 0;
}