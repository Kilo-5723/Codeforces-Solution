#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].first);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].second);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 1; i < a.size(); i++)
      a[i].second = min(a[i].second, a[i - 1].second);
    int sum = 0;
    while (k > 0) {
      sum += k;
      while (a.size() && a.back().first <= sum) a.pop_back();
      if (!a.size()) break;
      k -= a.back().second;
    }
    puts(a.size() ? "NO" : "YES");
  }
  return 0;
}