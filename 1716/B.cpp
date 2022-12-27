#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
void write(const vector<int> &a) {
  for (auto v : a) printf("%d ", v);
  puts("");
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    write(a);
    for (int i = 1; i < n; i++) {
      swap(a[0], a[i]);
      write(a);
    }
  }
  return 0;
}