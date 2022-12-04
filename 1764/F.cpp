#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
bool islet(char ch) { return ch >= '0' && ch <= '9'; }
ll read() {
  char ch = getchar();
  ll res = 0;
  while (!islet(ch)) ch = getchar();
  while (islet(ch)) {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res;
}
const int inf = 1e9 + 5;
struct edge {
  int u, v;
  int w;
};
vector<int> f;
int ff(int u) { return f[u] == u ? u : f[u] = ff(f[u]); }
void radix_sort(vector<edge> &e) {
  const int bsize = 1e5;
  int cnt[bsize];
  memset(cnt, 0, sizeof(cnt));
  for (auto [u, v, w] : e) cnt[w % bsize]++;
  for (int i = 1; i < bsize; i++) cnt[i] += cnt[i - 1];
  reverse(e.begin(), e.end());
  vector<edge> t(e.size());
  for (auto [u, v, w] : e) t[--cnt[w % bsize]] = {u, v, w};
  memset(cnt, 0, sizeof(cnt));
  swap(e, t);
  for (auto [u, v, w] : e) cnt[w / bsize]++;
  for (int i = 1; i < bsize; i++) cnt[i] += cnt[i - 1];
  reverse(e.begin(), e.end());
  for (auto [u, v, w] : e) t[--cnt[w / bsize]] = {u, v, w};
  swap(e, t);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<vector<ll>> a(n, vector<ll>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) a[i][j] = read();
  vector<edge> e;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      ll tmp = a[i][i] + a[j][j] - 2 * a[i][j];
      if (tmp % n == 0 && tmp / n < inf) e.push_back({j, i, (int)(tmp / n)});
    }
  // vector<int> ord(e.size());
  // for (int i = 0; i < e.size(); i++) ord[i] = i;
  // sort(ord.begin(), ord.end(), [&](int a, int b) { return e[a].w < e[b].w;
  // }); sort(e.begin(), e.end(), [](auto a, auto b) { return a.w < b.w; });
  radix_sort(e);
  f.resize(n);
  for (int i = 0; i < n; i++) f[i] = i;
  for (auto [u, v, w] : e) {
    if (ff(u) == ff(v)) continue;
    printf("%d %d %d\n", u + 1, v + 1, w);
    u = ff(u);
    v = ff(v);
    f[u] = v;
  }
  return 0;
}