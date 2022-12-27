#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
bool cmp(const vector<int> &a, const vector<int> &b) {
  for (int i = 0; i < a.size(); i++)
    if (a[i] < b[i]) return true;
  return false;
}
void add(int n, const vector<int> &p, vector<int> &cnt, int v) {
  for (int i = 0; i < p.size(); i++)
    while (!(n % p[i])) {
      cnt[i] += v;
      n /= p[i];
    }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  if (k == 1) {
    printf("%lld\n", 1ll * n * (n + 1) / 2);
    return 0;
  }
  vector<int> p, req;
  for (int i = 2; i * i <= k; i++)
    if (!(k % i)) {
      p.push_back(i);
      req.push_back(0);
      while (!(k % i)) {
        k /= i;
        req.back()++;
      }
    }
  if (k > 1) {
    p.push_back(k);
    req.push_back(1);
  }
  vector<int> cnt(req.size());
  ll ans = 0;
  for (int l = 0, r = 0; l < n; l++) {
    while (r < n && cmp(cnt, req)) add(a[r++], p, cnt, 1);
    if (cmp(cnt, req)) break;
    if (!cmp(cnt, req)) ans += n - r + 1;
    add(a[l], p, cnt, -1);
  }
  printf("%lld\n", ans);
  return 0;
}