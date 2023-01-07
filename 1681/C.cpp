#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
      for (int j = i; j; j--)
        if (a[j] < a[j - 1] || a[j] == a[j - 1] && b[j] < b[j - 1]) {
          swap(a[j], a[j - 1]);
          swap(b[j], b[j - 1]);
          ans.push_back({j, j + 1});
        }
    bool flg = true;
    for (int i = 1; i < n; i++) flg = flg && a[i] >= a[i - 1];
    for (int i = 1; i < n; i++) flg = flg && b[i] >= b[i - 1];
    // for (auto v : a) cout << v << ' ';
    // cout << endl;
    // for (auto v : b) cout << v << ' ';
    // cout << endl;
    if (!flg) {
      puts("-1");
      continue;
    }
    printf("%lu\n", ans.size());
    for (auto [i, j] : ans) printf("%d %d\n", i, j);
  }
  return 0;
}