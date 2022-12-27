#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(m);
  for (int i = 0; i < m; i++) scanf("%d", &a[i]);
  for (auto &v : a) v--;
  vector<int> b(n);
  bool flg = true;
  set<int> st;
  for (int i = 0; i < m - 1; i++) {
    int t = ((a[i + 1] - a[i] - 1) % n + n) % n + 1;
    if (b[a[i]])
      flg = flg && b[a[i]] == t;
    else if (st.count(t))
      flg = false;
    else {
      b[a[i]] = t;
      st.insert(t);
    }
  }
  if (!flg) {
    puts("-1");
    return 0;
  }
  int t = 1;
  for (auto &v : b)
    if (!v) {
      while (st.count(t)) t++;
      v = t++;
    }
  for (auto v : b) printf("%d ", v);
  puts("");
  return 0;
}