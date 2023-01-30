#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int main() {
  int tt;
  vector<ll> fact(maxn);
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", fact[n] * n % mod * (n - 1) % mod);
  }
  return 0;
}