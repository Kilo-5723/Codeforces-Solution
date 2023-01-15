#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int lim = 4e5, inf = 1e9;
vector<vector<int>> divs(lim);
struct Edge {
  int u, v, w;
};
int main() {
  for (int i = 2; i < lim; i++)
    if (!divs[i].size())
      for (int j = i; j < lim; j += i) divs[j].push_back(i);
  int n;
  scanf("%d", &n);
  vector eid(lim, vector<int>());
  vector<Edge> edge;
  int m = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    for (auto u : divs[a[i]])
      for (auto v : divs[a[i]]) {
        eid[u].push_back(m++);
        edge.push_back({u, v, i});
      }
  }
  int s, t;
  scanf("%d%d", &s, &t);
  if (s == t) {
    puts("1");
    printf("%d\n", s);
    return 0;
  }
  s--;
  t--;
  vector<int> prev(lim, -1);
  queue<int> que;
  for (auto v : divs[a[s]]) {
    que.push(v);
    prev[v] = -2;
  }
  while (que.size()) {
    int u = que.front();
    que.pop();
    if (!(a[t] % u)) {
      vector<int> ans;
      ans.push_back(t);
      for (int x = u; prev[x] != -2; x = edge[prev[x]].u) {
        ans.push_back(edge[prev[x]].w);
      }
      ans.push_back(s);
      reverse(ans.begin(), ans.end());
      printf("%lu\n", ans.size());
      for (auto v : ans) printf("%d ", v + 1);
      puts("");
      return 0;
    }
    for (auto i : eid[u]) {
      auto v = edge[i].v;
      if (!~prev[v]) {
        prev[v] = i;
        que.push(v);
      }
    }
  }
  puts("-1");
  return 0;
}