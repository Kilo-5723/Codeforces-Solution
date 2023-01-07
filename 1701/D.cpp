#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), l(n), r(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      l[i] = (i + 1) / (a[i] + 1) + 1;
      r[i] = min(n, a[i] ? (i + 1) / a[i] : n);
      mp[r[i]].push_back(i);
    }
    vector<int> b(n);
    set<pair<int, int>> st;
    for (int i = n; i >= 1; i--) {
      for (auto v : mp[i]) st.insert({l[v], v});
      auto [l, u] = *st.rbegin();
      st.erase({l, u});
      b[u] = i;
    }
    for (auto v : b) printf("%d ", v);
    puts("");
  }
  return 0;
}