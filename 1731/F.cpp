#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main() {
  int n;
  ll k;
  scanf("%d%lld", &n, &k);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int a = 0; a < i; a++)
      for (int b = a + 1; b < n - i; b++) ans+=calc(i,a)n-i-1,b);
  }
  return 0;
}