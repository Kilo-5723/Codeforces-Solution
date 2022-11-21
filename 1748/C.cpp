#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int solve(const vector<int>& arr) {
  if (!arr.size()) return 0;
  ll sum = 0;
  map<ll, int> cnt;
  for (auto v : arr) {
    sum += v;
    cnt[sum]++;
  }
  int res = 0;
  for (auto [val, appr] : cnt) res = max(res, appr);
  return arr[0] == 0 ? res : cnt[0];
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> arr;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      if (!t) {
        ans += solve(arr);
        arr = {};
      }
      arr.push_back(t);
    }
    printf("%d\n", ans + solve(arr));
    arr = {};
  }
  return 0;
}