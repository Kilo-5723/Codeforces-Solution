#include <cstdio>
#include <iostream>
using namespace std;

#include <algorithm>
#include <optional>
#include <queue>
#include <vector>

namespace maxflow {

typedef long long flow_t;

const flow_t inf_flow = 1e18;
const int inf_dep = 1e9;

struct FlowEdge {
  int from, to;
  flow_t cap, low = 0, flow = 0;
};

int num_node(const std::vector<FlowEdge> &edges) {
  int n = 0;
  for (const auto &e : edges) n = std::max({n, e.from, e.to});
  return n;
}
flow_t get_flow(const std::vector<FlowEdge> &edges, int s) {
  flow_t flow = 0;
  for (const auto &e : edges) {
    if (e.from == s) flow += e.flow;
  }
  return flow;
}

struct Maxflow {
  struct Edge {
    int from, to;
    flow_t cap;
  };
  int n;
  std::vector<std::vector<int>> eid;
  std::vector<Edge> edge;
  void build(const std::vector<FlowEdge> &edges) {
    n = num_node(edges);
    eid.assign(n + 1, {});
    edge.clear();
    int num_edges = 0;
    for (const auto &e : edges) {
      eid[e.from].push_back(num_edges++);
      edge.push_back({e.from, e.to, e.cap - e.flow});
      eid[e.to].push_back(num_edges++);
      edge.push_back({e.to, e.from, e.flow});
    }
  }
  std::vector<int> dis;
  std::vector<int> cur;
  bool bfs(int s, int t) {
    if (s > n || t > n) return false;
    dis.assign(n + 1, inf_dep);
    cur.assign(n + 1, 0);
    std::queue<int> que;
    dis[s] = 0;
    que.push(s);
    while (que.size()) {
      int u = que.front();
      que.pop();
      for (auto i : eid[u]) {
        const auto &e = edge[i];
        if (e.cap && dis[e.to] > dis[u] + 1) {
          dis[e.to] = dis[u] + 1;
          que.push(e.to);
        }
      }
    }
    return dis[t] < inf_dep;
  }
  flow_t dfs(int s, int t, flow_t flim) {
    if (s == t) return flim;
    flow_t flow = 0;
    for (int i = 0; i < eid[s].size() && flow < flim; i++) {
      auto &e = edge[eid[s][i]];
      if (dis[e.to] == dis[s] + 1 && e.cap) {
        auto detf = dfs(e.to, t, min(flim - flow, e.cap));
        flow += detf;
        e.cap -= detf;
        edge[eid[s][i] ^ 1].cap += detf;
      }
      if (flow == flim) break;
    }
    return flow;
  }
  flow_t maxflow(int s, int t) {
    flow_t flow = 0;
    while (bfs(s, t)) {
      flow += dfs(s, t, inf_flow);
    }
    return flow;
  }
  std::vector<FlowEdge> to_edge() {
    std::vector<FlowEdge> edges;
    for (int i = 0; i < edge.size(); i += 2)
      edges.push_back({
          .from = edge[i].from,
          .to = edge[i].to,
          .cap = edge[i].cap + edge[i ^ 1].cap,
          .flow = edge[i ^ 1].cap,
      });
    return edges;
  }
};
flow_t maximum_flow(std::vector<FlowEdge> &edges, int s, int t) {
  Maxflow g;
  g.build(edges);
  g.maxflow(s, t);
  edges = g.to_edge();
  return get_flow(edges, s);
}

}  // namespace maxflow

void dfs(int u, const vector<int> &a, vector<bool> &vis, vector<int> &arr) {
  if (vis[u]) return;
  vis[u] = true;
  arr.push_back(u);
  dfs(a[u], a, vis, arr);
}
using namespace maxflow;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  int s = 2 * n + 1, t = 2 * n + 2, m = t;
  vector<FlowEdge> edges;
  for (int i = 1; i <= n; i++)
    edges.push_back({.from = i * 2 - 1, .to = i * 2, .cap = 1});
  vector<bool> vis(n + 1, false);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      vector<int> arr;
      dfs(i, a, vis, arr);
      // for (auto v : arr) cout << v << ' ';
      // cout << endl;
      m++;
      edges.push_back({.from = s, .to = m, .cap = 1});
      for (auto v : arr)
        edges.push_back({.from = m, .to = v * 2 - 1, .cap = 1});
    }
  // cout << endl;
  vis.assign(n + 1, false);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      vector<int> arr;
      dfs(i, b, vis, arr);
      // for (auto v : arr) cout << v << ' ';
      // cout << endl;
      m++;
      edges.push_back({.from = m, .to = t, .cap = 1});
      for (auto v : arr) edges.push_back({.from = v * 2, .to = m, .cap = 1});
    }
  // cout << endl;
  maximum_flow(edges, s, t);
  vector<int> ans;
  for (int i = 0; i < n; i++)
    if (!edges[i].flow) ans.push_back(i + 1);
  printf("%lu\n", ans.size());
  for (auto v : ans) printf("%d ", v);
  puts("");
  return 0;
}