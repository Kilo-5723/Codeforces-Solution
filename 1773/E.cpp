#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> a(n);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    while (k--) {
      int t;
      scanf("%d", &t);
      a[i].push_back(t);
    }
    v.insert(v.end(), a[i].begin(), a[i].end());
  }
  sort(v.begin(), v.end());
  set<pair<int, int>> st;
  for (int i = 1; i < v.size(); i++) st.insert({v[i - 1], v[i]});
  int ans = v.size() - n;
  for (const auto &arr : a)
    for (int i = 1; i < arr.size(); i++)
      if (st.count({arr[i - 1], arr[i]})) ans--;
  printf("%d %d\n", ans, ans + n - 1);
  return 0;
}