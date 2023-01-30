#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxm = 1e6 + 5;
vector<int> cnt(maxm);
vector<vector<int>> arr(maxm);
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if (t <= m) arr[t].push_back(i);
  }
  for (int i = 1; i <= m; i++)
    for (int j = i; j <= m; j += i) cnt[j] += arr[i].size();
  int p = 1;
  for (int i = 1; i <= m; i++)
    if (cnt[i] > cnt[p]) p = i;
  printf("%d %d\n", p, cnt[p]);
  vector<int> ans;
  for (int i = 1; i <= m; i++)
    if (!(p % i))
      for (auto v : arr[i]) ans.push_back(v + 1);
  sort(ans.begin(), ans.end());
  for (auto v : ans) printf("%d ", v);
  puts("");
  return 0;
}