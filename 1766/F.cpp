#include <cstdio>
#include <iostream>

using namespace std;
#include "../template/graph/costflow.h"
#include "../template/graph/maxflow.h"
using maxflow::cost_t;
using maxflow::flow_t;
using maxflow::FlowEdge;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<flow_t> excess(n + 1);
  flow_t flow = 0;
  cost_t totc = 0;
  vector<FlowEdge> edge;
  vector<int> flg, flg2;
  while (m--) {
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
    flg2.push_back(w > 0);
    if (w > 0)
      edge.push_back(FlowEdge(x, y, w, c, 0, 0));
    else {
      // cout << totc << endl;
      totc += w * c;
      excess[x] -= c * 2;
      excess[y] += c * 2;
      edge.push_back(FlowEdge(y, x, -w, c, 0, 0));
    }
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
  auto res = maxflow::feasiflow(edge, excess, 1, n, true, true, 0);
  if (!res) {
    puts("Impossible");
    return 0;
  }
  auto [detf, detc] = *res;
  puts("Possible");
  flow += detf;
  totc += detc;
  for (int i = 0; i < edge.size(); i++)
    printf("%lld ",
           (flg2[i] ? edge[i].flow : edge[i].cap - edge[i].flow) * 2 + flg[i]);
  puts("");
  return 0;
}