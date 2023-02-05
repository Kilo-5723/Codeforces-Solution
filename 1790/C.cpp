#include <algorithm>
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
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n; j++) {
        int t;
        scanf("%d", &t);
        a[t] += j;
      }
    }
    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i + 1;
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
    for (auto v : ord) printf("%d ", v);
    puts("");
  }
  return 0;
}