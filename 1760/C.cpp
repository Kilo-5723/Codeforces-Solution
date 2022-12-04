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
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<int> b = a;
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++)
      if (a[i] != b[0])
        printf("%d ", a[i] - b[0]);
      else
        printf("%d ", a[i] - b[1]);
    puts("");
  }
  return 0;
}