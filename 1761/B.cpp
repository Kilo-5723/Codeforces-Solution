#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      st.insert(a[i]);
    }
    if (n == 1) {
      puts("1");
      continue;
    }
    if (st.size() > 2) {
      printf("%d\n", n);
      continue;
    }
    printf("%d\n", n / 2 + 1);
  }
  return 0;
}