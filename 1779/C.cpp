#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    ll sum = 0;
    multiset<ll> st;
    int ans = 0;
    for (int i = m; i < n; i++) {
      sum += a[i];
      st.insert(a[i]);
      while (sum < 0) {
        sum += -2 * *st.begin();
        st.erase(st.begin());
        ans++;
      }
    }
    st.clear();
    sum = 0;
    for (int i = m - 1; i > 0; i--) {
      sum += a[i];
      st.insert(a[i]);
      while (sum > 0) {
        sum += -2 * *st.rbegin();
        st.erase(prev(st.end()));
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}