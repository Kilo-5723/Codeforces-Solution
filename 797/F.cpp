#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int b, c;
    
    scanf("%d%d", &b, &c);
    mp[b] += c;
  }
  sort(a.begin(), a.end());
  vector<ll> dp(n, inf);
  dp[0] = 0;
  for (auto [k, v] : mp) {
    vector<ll> nxt(n, inf);
  }
  return 0;
}