#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int n = 3;
int dfs(int u, const vector<int> &a) {
  if (!u) return 0;
  return 1 + dfs(a[u], a);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int x;
    scanf("%d", &x);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    puts(dfs(x, a) == 3 ? "YES" : "NO");
  }
  return 0;
}