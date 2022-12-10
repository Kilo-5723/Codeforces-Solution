#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
void push(set<pair<int, int>> &zer, queue<int> &que, int pos) {
  while (zer.size()) {
    auto [v, p] = *prev(zer.end());
    if (v < pos) break;
    que.push(p);
    zer.erase({v, p});
  }
}
int solve(int s, const vector<int> &a, const vector<vector<int>> &e) {
  int n = e.size() - 1;
  vector<int> d(n + 1);
  for (int i = 1; i <= n; i++)
    for (auto v : e[i]) d[v]++;
  d[s] = -1;
  queue<int> que;
  set<pair<int, int>> zer;
  for (int i = 1; i <= n; i++)
    if (!d[i]) zer.insert({a[i], i});
  int res = n;
  push(zer, que, res);
  while (que.size()) {
    int u = que.front();
    que.pop();
    res--;
    for (auto v : e[u]) {
      d[v]--;
      if (!d[v]) zer.insert({a[v], v});
    }
    push(zer, que, res);
  }
  return res;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  vector<vector<int>> e(n + 1);
  vector<int> d(n + 1);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[v].push_back(u);
    d[u]++;
  }
  for (int i = 1; i <= n; i++) printf("%d ", solve(i, a, e));
  puts("");
  return 0;
}