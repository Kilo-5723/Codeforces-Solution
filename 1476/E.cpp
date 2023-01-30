#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1 << 20, mask = (1 << 5) - 1;
const int buff = 100;
char s[buff];
int read() {
  scanf("%s", s);
  int res = 0;
  for (int i = 0; s[i]; i++)
    res = (res << 5) + (s[i] == '_' ? 0 : s[i] - 'a' + 1);
  return res;
}
bool match(int tpl, int str) {
  if (!tpl) return true;
  return match(tpl >> 5, str >> 5) && !(tpl & mask) ||
         (tpl & mask) == (str & mask);
}
vector<int> matches(int org) {
  if (!org) return {0};
  auto res = matches(org >> 5);
  for (auto &v : res) v <<= 5;
  int n = res.size();
  res.resize(2 * n);
  for (int i = 0; i < n; i++) res[i + n] = res[i] + (org & mask);
  return res;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> a(n);
  vector<bool> vis(maxn);
  for (int i = 0; i < n; i++) vis[a[i] = read()] = true;
  vector<int> id(maxn);
  for (int i = 0; i < n; i++) id[a[i]] = i;
  bool flg = true;
  vector<vector<int>> e(maxn);
  for (int i = 0; i < m; i++) {
    int t = read(), k;
    scanf("%d", &k);
    k--;
    if (!match(a[k], t))
      flg = false;
    else {
      for (auto v : matches(t))
        if (v != a[k] && vis[v]) e[a[k]].push_back(v);
    }
  }
  if (!flg) {
    puts("NO");
    return 0;
  }
  vector<int> d(maxn);
  queue<int> que;
  for (int i = 0; i < n; i++)
    for (auto v : e[a[i]]) d[v]++;
  for (int i = 0; i < n; i++)
    if (!d[a[i]]) que.push(a[i]);
  vector<int> ans;
  while (que.size()) {
    int u = que.front();
    ans.push_back(u);
    que.pop();
    for (auto v : e[u])
      if (!--d[v]) que.push(v);
  }
  if (ans.size() != n) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (auto v : ans) printf("%d ", id[v] + 1);
  puts("");
  return 0;
}