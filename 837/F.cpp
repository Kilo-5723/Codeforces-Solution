#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef __int128 li;
typedef long long ll;
bool isless(vector<li> &a, li m) {
  li sum = 0;
  for (auto v : a)
    if (v >= m) return false;
  return true;
}
void presum(vector<li> &a) {
  li sum = 0;
  for (auto &v : a) {
    li t = v;
    v += sum;
    sum += t;
  }
}
bool check(li a, li b, li c, li x, li s) {
  {
    double v = 1.0 * c;
    v += 1.0 * b * x;
    v += 1.0 * a * x * (x + 1) / 2;
    if (v > 2 * s + 10) return true;
  }
  li v = c;
  v += b * x;
  v += a * x * (x + 1) / 2;
  return v >= s;
}
ll calc(li a, li b, li c, li s) {
  ll l = -1, r = 2 * s + 10;
  while (r - l > 1) {
    li m = (l + r) / 2;
    if (check(a, b, c, m, s))
      r = m;
    else
      l = m;
  }
  return r;
}
int main() {
  int n;
  ll m;
  scanf("%d%lld", &n, &m);
  vector<li> a;
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if (a.size() || t) a.push_back(t);
  }
  if (a.size() < 4) {
    if (a.size() == 2) a.insert(a.begin(), 0);
    printf("%lld\n", calc(a[0], a[1], a[2], m));
    return 0;
  }
  int cnt = 0;
  while (isless(a, m)) {
    cnt++;
    presum(a);
  }
  printf("%d\n", cnt);
  return 0;
}