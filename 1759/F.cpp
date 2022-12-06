#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, p;
    scanf("%d%d", &n, &p);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    set<int> left, right;
    for (int i = 1; i <= n; i++)
      if (a[i] < a[n])
        left.insert(a[i]);
      else
        right.insert(a[i]);
    if (left.size() == a[n]) {
      int k = p - 1;
      while (right.count(k)) k--;
      printf("%d\n", max(0, k - a[n]));
      continue;
    }
    a[n - 1]++;
    for (int i = n - 1; a[i] == p; i--) {
      a[i] = 0;
      a[i - 1]++;
    }
    for (int i = 0; i < n; i++) left.insert(a[i]);
    int k = a[n] - 1;
    while (left.count(k)) k--;
    printf("%d\n", p - (a[n] - max(0, k)));
  }
  return 0;
}