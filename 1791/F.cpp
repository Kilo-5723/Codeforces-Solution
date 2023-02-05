#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int calc(int n) { return n ? n % 10 + calc(n / 10) : 0; }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> a(n);
    for (auto &v : a) scanf("%d", &v);
    set<int> st;
    for (int i = 0; i < n; i++) st.insert(i);
    while (q--) {
      int op, x, y;
      scanf("%d", &op);
      vector<int> arr;
      switch (op) {
        case 1:
          int l, r;
          scanf("%d%d", &l, &r);
          l--;
          r--;
          arr.clear();
          for (auto it = st.lower_bound(l); it != st.end() && *it <= r;
               st.erase(it++))
            arr.push_back(*it);
          for (auto v : arr)
            if ((a[v] = calc(a[v])) >= 10) st.insert(v);
          break;
        case 2:
          int x;
          scanf("%d", &x);
          printf("%d\n", a[x - 1]);
          break;
      }
    }
  }
  return 0;
}