#include <cstdio>
#include <iostream>
#include <vector>

#include "../template/graph/costflow.h"

using namespace std;
using namespace costflow;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<flow_t> excess(n + 1);
  flow_t flow = 0;
  cost_t totc = 0;
  vector<CostEdge> edge;
  vector<int> flg, flg2;
  for (int i = 0; i < m; i++) {
    int x, y, c, w;
    scanf("%d%d%d%d", &x, &y, &c, &w);
    flg.push_back(c & 1);
    if (c & 1) {
      excess[x]--;
      excess[y]++;
      totc += w;
    }
    w *= 2;
    c /= 2;
    edge.push_back({.from = x, .to = y, .cost = w, .cap = c});
  }
  if (excess[1] & 1) {
    excess[1]--;
    excess[n]++;
  }
  for (auto &v : excess) {
    if (v & 1) {
      puts("Impossible");
      return 0;
    }
    v /= 2;
  }
  for (int i = 1; i <= n; i++) {
    if (excess[i] > 0)
      edge.push_back({.from = n + 1, .to = i, .cost = 0, .cap = excess[i]});
    if (excess[i] < 0)
      edge.push_back({.from = i, .to = n + 2, .cost = 0, .cap = -excess[i]});
  }
  edge.push_back({.from = n, .to = 1, .cost = 0, .cap = inf_flow});
  maximum_flow(edge, n + 1, n + 2);
  edge.pop_back();
  for (int i = m; i < edge.size(); i++)
    if (edge[i].flow != edge[i].cap) {
      puts("Impossible");
      return 0;
    }
  edge.resize(m);
  puts("Possible");
  edge.pop_back();
  for (int i = 0; i < m; i++) printf("%lld ", edge[i].flow * 2 + flg[i]);
  puts("");
  return 0;
}