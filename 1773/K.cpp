#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<pair<int, int>> ans;
  int l = 1, r = n;
  if (k == n) {
    if (k == 1) {
      puts("YES");
      puts("0");
      return 0;
    }
    puts("NO");
    return 0;
  }
  if (k == 1) {
    puts("YES");
    if (n == 2) {
      puts("1");
      puts("1 2");
      return 0;
    }
    printf("%d\n", n);
    for (int i = 0; i < n; i++) printf("%d %d\n", i + 1, (i + 1) % n + 1);
    return 0;
  }
  while (k) {
    if (k == 1) {
      ans.push_back({l, l + 1});
      break;
    }
    for (int i = l; i < r; i++) ans.push_back({i, r});
    l++;
    r--;
    k -= 2;
  }
  puts("YES");
  printf("%lu\n", ans.size());
  for (auto [u, v] : ans) printf("%d %d\n", u, v);
  return 0;
}