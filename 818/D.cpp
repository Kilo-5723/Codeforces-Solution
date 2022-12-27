#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main() {
  int n, a;
  scanf("%d%d", &n, &a);
  vector<int> arr(n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  set<pair<int, int>> st;
  map<int, int> cnt;
  for (auto v : arr) st.insert({0, v});
  st.erase({0, a});
  int tot = 0;
  for (auto v : arr) {
    if (v == a) {
      tot++;
      while (st.size() && st.begin()->first < tot) st.erase(st.begin());
    }
    if (!st.count({cnt[v], v})) continue;
    st.erase({cnt[v], v});
    st.insert({++cnt[v], v});
  }
  if (!st.size())
    puts("-1");
  else
    printf("%d\n", st.begin()->second);
  return 0;
}