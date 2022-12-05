#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
map<ll, set<int>> pos;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    ll t;
    scanf("%lld", &t);
    pos[t].insert(i);
  }
  for (auto &[key, st] : pos) {
    while (st.size() > 1) {
      st.erase(st.begin());
      auto v = *st.begin();
      st.erase(v);
      pos[key * 2].insert(v);
    }
  }
  vector<pair<int, ll>> arr;
  for (auto &[key, st] : pos) {
    for (auto val : st) arr.push_back({val, key});
  }
  sort(arr.begin(), arr.end());
  printf("%lu\n", arr.size());
  for (auto [pos, val] : arr) printf("%lld ", val);
  puts("");
  return 0;
}