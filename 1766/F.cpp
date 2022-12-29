#include <cstdio>
#include <iostream>
#include <vector>

#include "../template/graph/costflow.h"

using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<costflow::flow_t> excess(n + 1, 0);
  vector<costflow::CostEdge> edges;
  while (m--) {
    int u, v, c, w;
    scanf("%d%d%d%d", &u, &v, &c, &w);
    excess[u] -= c & 1;
    excess[v] += c & 1;
    edges.push_back({.from = u, .to = v, .cost = w * 2, .cap = c / 2});
  }
  costflow::CostFlow cf;
  return 0;
}