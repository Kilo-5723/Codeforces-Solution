#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const ll init = 1e9;
const int buff = 2e5;
char s[buff];
vector mnm(1 << 10, vector<ll>(2, -1));
ll minim(int bit, bool flg) {
  if (~mnm[bit][flg]) return mnm[bit][flg];
  ll res = 0;
  if (flg) {
    int cnt = 0;
    for (int i = 0; i < 10; i++) cnt += (bit >> i & 1);
    if (cnt & 1) return mnm[bit][flg] = 1e18;
    for (int i = 0; i < 10; i++)
      if (bit >> i & 1) res = res * 10 + i;
  } else {
    bool flg = false;
    for (int i = 1; i < 10; i++)
      if (bit >> i & 1) {
        res = res * 10 + i;
        if (!flg && (bit & 1)) res *= 10;
        flg = true;
      }
  }
  return mnm[bit][flg] = res;
}
ll solve(int bit, ll n, ll p, bool flg) {
  // cout << n << ' ' << minim(bit, flg) << endl;
  if (!p) return bit ? -1 : 0;
  if (minim(bit, flg) > n) return -1;
  for (int i = 9; i >= 0; i--)
    if (n >= p * i) {
      auto res =
          solve(bit ^ (flg || i ? (1 << i) : 0), n - p * i, p / 10, flg || i);
      if (~res) return res + p * i;
    }
  return -1;
}
bool solve(char s[]) {
  int k = strlen(s);
  char *p = s;
  int bit = 0;
  bool flg = false;
  while (k-- > 10) {
    int x = *p++ - '0';
    flg = flg || x;
    bit ^= (flg ? 1 << x : 0);
  }
  ll n;
  sscanf(p, "%lld", &n);
  ll res = solve(bit, n, init, flg);
  if (!~res) return false;
  *p = 0;
  p = s;
  while (*p == '0') p++;
  if (*p)
    printf("%s%010lld\n", p, res);
  else
    printf("%lld\n", res);
  return true;
}
void decrease(char s[], int p) {
  while (s[p - 1] == '0') s[--p] = '9';
  s[p - 1]--;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    if (strlen(s) < 10) {
      reverse(s, s + strlen(s));
      for (int i = strlen(s); i < 10; i++) s[i] = '0';
      s[10] = 0;
      reverse(s, s + strlen(s));
    }
    int k = strlen(s);
    decrease(s, k);
    while (!solve(s)) decrease(s, k);
  }
  return 0;
}