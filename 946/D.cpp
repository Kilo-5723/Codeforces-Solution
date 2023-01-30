#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
const int buff = 1e3;
char s[buff];
vector<pair<int, int>> read() {
  scanf("%s", s);
  vector<int> arr;
  int n = strlen(s);
  for (int i = 0; s[i]; i++)
    if (s[i] == '1') arr.push_back(i);
  vector<pair<int, int>> res = {{arr.size(), 0}};
  for (int i = 0; i < arr.size(); i++)
    for (int j = i; j < arr.size(); j++)
      res.push_back({i + arr.size() - j - 1, arr[j] - arr[i] + 1});
  sort(res.begin(), res.end());
  res.resize(unique(res.begin(), res.end(),
                    [](pair<int, int> a, pair<int, int> b) {
                      return a.first == b.first;
                    }) -
             res.begin());
  return res;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> dp(k + 1, 0);
  for (int i = 0; i < n; i++) {
    auto arr = read();
    vector<int> nxt(k + 1, inf);
    for (auto [v, t] : arr)
      for (int i = v; i <= k; i++) nxt[i] = min(nxt[i], dp[i - v] + t);
    dp = nxt;
  }
  int ans = inf;
  for (auto v : dp) ans = min(ans, v);
  printf("%d\n", ans);
  return 0;
}