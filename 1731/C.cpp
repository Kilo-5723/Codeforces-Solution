#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 5;
vector<int> mindiv(maxn);
vector<int> prime;
vector<int> d(maxn);
int main() {
  for (int i = 2; i < maxn; i++) mindiv[i] = i;
  for (int i = 2; i < maxn; i++) {
    if (mindiv[i] == i) prime.push_back(i);
    for (int j = 0;
         j < prime.size() && prime[j] <= mindiv[i] && i * prime[j] < maxn; j++)
      mindiv[i * prime[j]] = prime[j];
  }
  // for (int i = 2; i <= 10; i++) cout << mindiv[i] << ' ';
  // cout << endl;
  int cnt1 = 1, cnt0 = 0;
  d[0] = 1;
  d[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (mindiv[i] == i) {
      d[i] = 0;
      cnt0++;
      continue;
    }
    bool flg = true;
    int t = i;
    while (t % mindiv[i] == 0) {
      // cout << t << ' ' << mindiv[i] << endl;
      t = t / mindiv[i];
      flg = !flg;
    }
    d[i] = flg && d[t];
    if (d[i] == 1)
      cnt1++;
    else
      cnt0++;
  }
  vector<int> opr;
  for (int i = 0; i < maxn; i++)
    if (d[i] == 1) opr.push_back(i);
  // printf("%d %d\n", cnt1, cnt0);
  // cout << opr.size() << endl;
  // return 0;
  // for (int i = 0; i < 10; i++) cout << opr[i] << ' ';
  // cout << endl;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<int> s(n + 1);
    for (int i = 0; i < n; i++) s[i + 1] = s[i] ^ a[i];
    vector<int> mp(4 * n);
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
      // cout << s[i] << endl;
      for (auto v : opr)
        if ((s[i] ^ v) < mp.size()) ans += mp[s[i] ^ v];
      mp[s[i]]++;
    }
    printf("%lld\n", (1ll * n * (n + 1) / 2) - ans);
  }
  return 0;
}