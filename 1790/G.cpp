#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int inf = 1e9;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int p, b;
    scanf("%d%d", &p, &b);
    vector<int> c(n + 1);
    vector<int> a(p);
    for (auto &v : a) scanf("%d", &v);
    while (b--) {
      int t;
      scanf("%d", &t);
      c[t] = 1;
    }
    vector<int> d(n + 1, inf);
    vector e(n + 1, vector<int>{});
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    queue<int> que;
    que.push(1);
    d[1] = 0;
    while (que.size()) {
      int u = que.front();
      que.pop();
      for (auto v : e[u])
        if (d[v] > d[u] + 1) {
          d[v] = d[u] + 1;
          if (c[v]) que.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
      if (c[i])
        for (auto j : e[i]) c[i] += bool(c[j]);
    int cnt = 0, sum = 0;
    for (auto u : a) {
      int mxm = 0;
      for (auto v : e[u]) mxm = max(mxm, c[v]);
      cnt += bool(mxm);
      sum += mxm;
    }
    bool flg = false;
    for (auto u : a)
      if (d[u] < inf) {
        int mxm = 0;
        for (auto v : e[u]) mxm = max(mxm, c[v]);
        cnt -= bool(mxm);
        sum -= mxm;
        flg = flg || sum > cnt || cnt >= d[u] - 1;
        cnt += bool(mxm);
        sum += mxm;
      }
    puts(flg ? "YES" : "NO");
  }
  return 0;
}