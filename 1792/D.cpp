#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const int base = 20;
vector<ll> subs(ll a) {
  if (!a) return {0};
  vector<ll> res = subs(a / base);
  for (auto &v : res) v *= base;
  int n = res.size();
  for (int i = 0; i < n; i++) res.push_back(res[i] + a % base);
  return res;
}
vector<int> to_arr(ll n) {
  if (!n) return {};
  vector<int> res = to_arr(n / base);
  res.push_back(n % base);
  return res;
}
ll to_num(vector<int> a) {
  ll res = 0;
  for (auto t : a) res = res * base + t;
  return res;
}
int solve(vector<int> a, const vector<ll> &st) {
  vector<int> p(a.size() + 1);
  for (int i = 0; i < a.size(); i++) p[a[i]] = i;
  vector<int> b(a.size(), 0);
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    int t = a[i];
    b[t - 1] = i + 1;
    ll v = to_num(b);
    auto it = lower_bound(st.begin(), st.end(), v);
    if (it < st.end() && *it == v) ans = i + 1;
    // cout << to_num(a) << ' ' << to_num(b) << ' ' << i << ' ' << ans << endl;
  }
  return ans;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector a(n, vector<int>(m));
    set<ll> st;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
      vector<int> p(m + 1);
      for (int j = 0; j < m; j++) p[a[i][j]] = j + 1;
      vector<int> b;
      for (int j = 0; j < m; j++) {
        b.push_back(p[j + 1]);
        st.insert(to_num(b));
      }
    }
    for (int i = 0; i < n; i++) {
      int ans = 0;
      vector<int> b;
      for (int j = 0; j < m; j++) {
        b.push_back(a[i][j]);
        if (st.count(to_num(b))) ans = j + 1;
      }
      printf("%d ", ans);
    }
    // for (int i = 0; i < n; i++) solve(a[i], st);
    puts("");
  }
  return 0;
}