#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int inf = 1e9;
vector<vector<int>> st;
vector<int> log22;
int query(int l, int r) {
  int k = log22[r - l + 1];
  return min(st[l][k], st[r - (1 << k) + 1][k]);
}
bool check(int l, int r, int x) { return query(l, r - x) <= x; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  map<int, int> last;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if (last.count(t)) a[last[t]] = i - last[t];
    a[last[t] = i] = inf;
  }
  st.resize(n);
  for (int i = 0; i < n; i++) st[i].push_back(a[i]);
  for (int j = 1; j <= n; j <<= 1)
    for (int i = 0; i + j * 2 <= n; i++)
      st[i].push_back(min(st[i].back(), st[i + j].back()));
  log22.resize(n + 1);
  cout << query(1, 3) << endl;
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  cout << endl;
  for (int i = 2; i <= n; i++) log22[i] = log22[i >> 1] + 1;
  while (m--) {
    int p, q;
    scanf("%d%d", &p, &q);
    p--;
    q--;
    int l = 0, r = q - p + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (m == 5)
        cout << p << ' ' << q << ' ' << m << ' ' << query(p, q - m) << endl;
      if (check(p, q, m))
        r = m;
      else
        l = m;
    }
    printf("%d\n", r == q - p + 1 ? -1 : r);
  }
  return 0;
}