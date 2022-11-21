#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 105;
char s[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<vector<int>> e(n), r(n);
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      for (int j = 0; j < n; j++)
        if (s[j] == '1') {
          r[i].push_back(j);
          e[j].push_back(i);
          d[i]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < n; i++)
      if (!d[i]) que.push(i);
    vector<int> ord;
    while (que.size()) {
      auto u = que.front();
      que.pop();
      ord.push_back(u);
      for (auto v : e[u])
        if (!--d[v]) que.push(v);
    }
    vector<bitset<maxn>> ans(n);
    for (int i = 0; i < n; i++) ans[i][i] = true;
    reverse(ord.begin(), ord.end());
    for (auto u : ord)
      for (auto v : r[u]) ans[v] |= ans[u];
    for (int i = 0; i < n; i++) {
      printf("%zu", ans[i].count());
      for (int j = 0; j < n; j++)
        if (ans[i][j]) printf(" %d", j + 1);
      puts("");
    }
  }
  return 0;
}