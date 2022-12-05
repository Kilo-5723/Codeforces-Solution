#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s += a[i];
  }
  s = (s + 1) / 2;
  for (int i = 0; i < n; i++) {
    s -= a[i];
    if (s <= 0) {
      printf("%d\n", i + 1);
      break;
    }
  }
  return 0;
}