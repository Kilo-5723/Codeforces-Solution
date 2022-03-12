#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
const int maxn = 105, maxk = 1e4 + 5;
multiset<int, greater<int>> st[maxn];
bool check(int p, int n) {
  if (*st[p].begin() != p) return false;
  auto it = st[p].end();
  it--;
  if (*it != p) return false;
  return true;
}
int ans[maxk][maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < n; j++) {
      int tmp;
      scanf("%d", &tmp);
      st[i].insert(tmp);
    }
  int k = 0;
  for (int i = n; i > 1; i--) {
    while (!check(i, n)) {
      for (int j = 1; j < i; j++) {
        ans[k][j - 1] = *st[j].begin();
        st[j + 1].insert(*st[j].begin());
        st[j].erase(st[j].begin());
      }
        // for (auto v:st[3]) printf("%d ",v);
        // puts("");
      auto it = st[i].begin();
      while (*it == i) it++;
      for (int j = i; j <= n; j++) ans[k][j - 1] = *it;
      st[1].insert(*it);
      st[i].erase(it);
      k++;
      // for (int j=1;j<=n;j++){
      //   printf("%d:\n",j);
      //   for (auto v:st[j]) printf("%d ",v);
      //   puts("");
      // }
    }
    // getchar();
  }
  printf("%d\n",k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++)
      printf("%d%c", ans[i][j], j < n - 1 ? ' ' : '\n');
  }
  return 0;
}