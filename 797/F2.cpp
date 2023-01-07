#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <optional>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
bool moveleft(const vector<int> &a, const vector<int> &b, vector<int> &c) {
  int n = c.size();
  int p = n - 1;
  while (p - 1 >= 0 && c[p] - c[p - 1] == 1) p--;
  if (p == 0 && c[0] == 0) return false;
  ll res = 0;
  for (int i = p; i < n; i++) {
    res -= abs(b[c[i]] - a[i]);
    c[i]--;
    res += abs(b[c[i]] - a[i]);
  }
  if (res < 0) return true;
  for (int i = p; i < n; i++) c[i]++;
  return false;
}
ll cost(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
  int n = c.size();
  ll res = 0;
  for (int i = 0; i < n; i++) res += abs(b[c[i]] - a[i]);
  return res;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<int> b;
  for (int i = 0; i < m; i++) {
    int x, c;
    scanf("%d%d", &x, &c);
    while (c--) b.push_back(x);
  }
  m = b.size();
  if (m < n) {
    puts("-1");
    return 0;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> c;
  ll sum = 0;
  vector<int> d(n);
  for (int i = 0; i < n; i++) d[i] = b[m - n + i];
  b.resize(m - n);
  for (int i = 0; i < n; i++) {
    b.push_back(d[i]);
    int las = c.size() ? c.back() : -1;
    int p = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    if (p == b.size()) p--;
    c.push_back(max(las + 1, p));
    // cout << p << ' ' << las + 1 << ' ' << b.size() << endl;
    // moveright(a, b, c);
    while (moveleft(a, b, c))
      ;
  }
  printf("%lld\n", cost(a, b, c));
  return 0;
}