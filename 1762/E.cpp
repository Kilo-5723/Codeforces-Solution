#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main() {
  int n;
  scanf("%d", &n);
  vector<ll> siz(n, 1);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) siz[j] = (siz[j] + siz[i]) % mod;
  }
  return 0;
}