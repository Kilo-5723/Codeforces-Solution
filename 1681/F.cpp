#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<vector<pair<int, int>>> e(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  vector<map<int, int>> dp(n + 1);
  dfs1(1, 1, e);
  return 0;
}