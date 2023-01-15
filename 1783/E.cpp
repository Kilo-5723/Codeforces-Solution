#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int> &a, int k, int n) {
  for (int i = 1; i <= n; i += k)
    if (a[i] < i) return false;
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    vector<int> mnm(n + 1, n + 1);
    for (int i = 0; i < n; i++) mnm[a[i]] = min(mnm[a[i]], b[i]);
    // for (int i = 0; i <= n; i++) cout << mnm[i] << ' ';
    // puts("");
    for (int i = n; i; i--) mnm[i - 1] = min(mnm[i - 1], mnm[i]);
    // for (int i = 0; i <= n; i++) cout << mnm[i] << ' ';
    // cout << endl;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
      if (check(mnm, i, n)) ans.push_back(i);
    printf("%lu\n", ans.size());
    for (auto v : ans) printf("%d ", v);
    puts("");
  }
  return 0;
}