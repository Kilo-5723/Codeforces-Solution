#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    puts(n < k * k || (n - k & 1) ? "NO" : "YES");
  }
  return 0;
}