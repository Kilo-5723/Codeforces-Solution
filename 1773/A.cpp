#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> rev(vector<int> a, int n) {
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) b[a[i]] = i;
  return b;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    vector<int> p(n + 1), q(n + 1);
    vector<int> arr, one;
    vector<pair<int, int>> two;
    for (int i = 1; i <= n; i++) {
      p[i] = a[i];
      if (a[i] == i) {
        one.push_back(i);
      } else if (a[a[i]] == i) {
        if (i < a[i]) two.push_back({i, a[i]});
      } else {
        arr.push_back(i);
      }
    }
    for (auto u : one) {
      if (arr.size()) swap(p[u], p[arr.back()]);
      arr.push_back(u);
    }
    for (auto [u, v] : two) {
      if (arr.size() > 1) swap(p[v], p[arr[arr.size() - 2]]);
      if (arr.size()) swap(p[u], p[arr.back()]);
      arr.push_back(u);
      arr.push_back(v);
    }
    for (int i = 1; i <= n; i++) q[a[p[i]]] = i;
    bool flg = true;
    for (int i = 1; i <= n; i++) {
      if (a[p[q[i]]] != i) flg = false;
      if (p[i] == i) flg = false;
      if (q[i] == i) flg = false;
    }
    if (!flg) {
      puts("Impossible");
      continue;
    }
    puts("Possible");
    for (int i = 1; i <= n; i++) printf("%d ", p[i]);
    puts("");
    for (int i = 1; i <= n; i++) printf("%d ", q[i]);
    puts("");
  }
  return 0;
}