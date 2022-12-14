#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main() {
  int n;
  scanf("%d", &n);
  vector<ll> qpow(n);
  qpow[0] = 1;
  for (int i = 1; i < n; i++) qpow[i] = qpow[i - 1] * 10 % mod;
  for (int i = 1; i < n; i++)
    printf("%lld ",
           (18 * qpow[n - i] + (n - i - 1) * 81 * qpow[n - i - 1]) % mod);
  puts("10");
  return 0;
}