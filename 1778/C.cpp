#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int inf = 1e9, maxd = 10, alpha = 26;
void norm(vector<char> &a, vector<char> &b) {
  vector<int> cnt(alpha);
  for (auto c : a) cnt[c - 'a']++;
  vector<int> ord(alpha);
  for (int i = 0; i < 26; i++) ord[i] = i;
  sort(ord.begin(), ord.end(), [&](int i, int j) { return cnt[i] > cnt[j]; });
  vector<int> pos(alpha);
  for (int i = 0; i < 26; i++) pos[ord[i]] = i;
  for (auto &c : a) c = pos[c - 'a'] + 'a';
  for (auto &c : b) c = pos[c - 'a'] + 'a';
}
ll solve(vector<char> &a, vector<char> &b, int bin) {
  int p = -1;
  ll res = 0;
  for (int i = 0; i < a.size(); i++)
    if (a[i] == b[i] || (bin >> a[i] - 'a' & 1))
      res += i - p;
    else
      p = i;
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    map<char, int> cnt;
    vector<char> a(n + 1), b(n + 1);
    scanf("%s", a.data());
    scanf("%s", b.data());
    a.pop_back();
    b.pop_back();
    norm(a, b);
    ll ans = 0;
    for (int bin = 0; bin < (1 << maxd); bin++)
      if (__builtin_popcount(bin) == k) ans = max(ans, solve(a, b, bin));
    printf("%lld\n", ans);
  }
  return 0;
}