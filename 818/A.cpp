#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, k;
  scanf("%lld%lld", &n, &k);
  printf("%lld %lld %lld\n", n / 2 / (k + 1), n / 2 / (k + 1) * k,
         n - n / 2 / (k + 1) * (k + 1));
  return 0;
}