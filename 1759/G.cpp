#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n / 2);
    for (int i = 0; i < n / 2; i++) scanf("%d", &a[i]);
    bool flg = true;
    vector<int> cnt(n + 1);
    for (auto v : a) {
      if (cnt[v]) flg = false;
      cnt[v] = true;
    }
    if (!flg) {
      puts("-1");
      continue;
    }
    vector<int> b(n / 2);
    set<int> st;
    for (int i = 1; i <= n; i++)
      if (!cnt[i]) st.insert(i);
    // for (auto v : st) cout << v << ' ';
    // cout << endl;
    for (int i = n / 2-1; i >= 0; i--) {
      auto it = st.upper_bound(a[i]);
      // cout<<a[i]<<endl;
      if (it == st.begin()) {
        flg = false;
        break;
      }
      it--;
      b[i] = *it;
      st.erase(it);
      // printf("%d %d\n", a[i], b[i]);
    }
    if (!flg) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < n / 2; i++) printf("%d %d ", b[i], a[i]);
    puts("");
  }
  return 0;
}