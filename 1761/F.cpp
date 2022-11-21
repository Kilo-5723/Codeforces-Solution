#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 4e3 + 5;
vector<vector<int>> e;
vector<bool> vis;
vector<int> arr;
char s[maxn];
void dfs(int u) {
  if (vis[u]) return;
  arr.push_back(u);
  vis[u] = true;
  for (auto v : e[u]) dfs(v);
}
bool perfect(const vector<int> &arr) {
  if (arr.size() == 1) return false;
  for (auto u : arr)
    if (e[u].size() < arr.size() - 1) return false;
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    e.assign(n, {});
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      for (int j = 0; j < n; j++)
        if (s[j] == '1') {
          e[i].push_back(j);
          e[j].push_back(i);
        }
    }
    vis.assign(n, false);
    vector<vector<int>> subg;
    for (int i = 0; i < n; i++)
      if (!vis[i]) {
        arr = {};
        dfs(i);
        sort(arr.begin(), arr.end(),
             [](int a, int b) { return e[a].size() < e[b].size(); });
        subg.push_back(arr);
      }
    if (subg.size() == 1) {
      puts("0");
      continue;
    }
    bool flg = false;
    for (const auto &arr : subg)
      if (!perfect(arr)) {
        puts("1");
        printf("%d\n", arr[0] + 1);
        flg = true;
        break;
      }
    if (flg) continue;
    sort(subg.begin(), subg.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return a.size() < b.size();
         });
    if (subg.size() == 2) {
      printf("%lu\n", subg[0].size());
      for (auto u : subg[0]) printf("%d ", u + 1);
      puts("");
      continue;
    }
    puts("2");
    printf("%d %d\n", subg[0][0] + 1, subg[1][0] + 1);
  }
  return 0;
}