#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
char a[maxn], b[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s%s", a, b);
    bool flg = true;
    for (int i = 1; i < n; i++)
      if ((a[i] ^ b[i]) != (a[0] ^ b[0])) flg = false;
    if (!flg) {
      puts("NO");
      continue;
    }
    puts("YES");
    flg = a[0] ^ b[0];
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
      if (a[i] - '0') {
        ans.push_back({i + 1, i + 1});
        flg ^= 1;
      }
    if (flg) {
      ans.push_back({1, 1});
      ans.push_back({2, n});
      ans.push_back({1, n});
    }
    printf("%lu\n", ans.size());
    for (auto pr : ans) printf("%d %d\n", pr.first, pr.second);
  }
  return 0;
}