#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 5, alpha = 12, maxm = 12, inf = 1e9;
int next[maxn], ch[maxn][alpha], val[maxn], dp[maxn][1 << alpha], siza;
char s[alpha << 2];
int l, r;
bool vis[alpha];
int trans(string str) {
  string res;
  int p = alpha << 1;
  memset(vis, false, sizeof(vis));
  memset(s, 0, sizeof(s));
  l = alpha << 2;
  r = 0;
  for (auto ch : str) {
    if (vis[ch - 'a']) {
      if (s[p - 1] == ch)
        p--;
      else if (s[p + 1] == ch)
        p++;
      else
        return false;
    } else {
      vis[ch - 'a'] = true;
      if (!s[p - 1])
        s[--p] = ch;
      else if (!s[p + 1])
        s[++p] = ch;
      else
        return false;
    }
    l = min(l, p);
    r = max(r, p);
  }
  r++;
  return true;
}
void add(int &rt, char *s, int v) {
  if (~rt) rt = ++siza;
  if (!*s) val[rt] = v;
  add(ch[rt][*s - 'a'], s++, v);
}
void build(){
  queue<int>
}
int main() {
  int n;
  cin >> n;
  siza = 1;
  int rt = 0;
  while (n--) {
    int k;
    string str;
    cin >> k >> str;
    if (trans(str)) {
      add(rt, s + l, k);
      reverse(s + l, s + r);
      printf("%s %d %d\n", s + l, l, r);
      add(rt, s + l, k);
    }
  }
  fill(dp[0], dp[maxn], -inf);
  dp[0][0] = 0;
  for (int i=0;i<12;i++){

  }
  return 0;
}