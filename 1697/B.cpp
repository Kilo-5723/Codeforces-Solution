#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<ll> a(n), s(n + 1);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%lld\n", s[n - x + y] - s[n - x]);
  }
  return 0;
}