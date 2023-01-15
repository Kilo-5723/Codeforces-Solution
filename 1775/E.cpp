#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i < n; i++) a[i] += a[i - 1];
    ll mxm = 0, mnm = 0;
    for (auto v : a) {
      mxm = max(mxm, v);
      mnm = min(mnm, v);
    }
    printf("%lld\n", mxm - mnm);
  }
  return 0;
}