#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int inf = 1e9;
vector<int> vis;
void bfs(int s, vector<int> &dis, vector<vector<int>> &e, int &mnm) {
  queue<pair<int, int>> que;
  que.push({s, dis[s] = 0});
  while (que.size()) {
    auto [u, d] = que.front();
    que.pop();
    if (d > mnm / 2 + 1) break;
    for (auto v : e[u])
      if (dis[v] > d + 1)
        que.push({v, dis[v] = d + 1});
      else if (dis[v] >= d)
        mnm = min(mnm, d + dis[v] + 1);
  }
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, s;
    scanf("%d%d", &n, &s);
    vector e(n + 1, vector<int>{});
    vector<int> a(n - 1);
    for (auto &v : a) scanf("%d", &v);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    vector<int> dis(n + 1, inf);
    int ans = inf;
    bfs(s, dis, e, ans);
    for (auto v : a) {
      bfs(v, dis, e, ans);
      printf("%d ", ans);
    }
    puts("");
  }
  return 0;
}