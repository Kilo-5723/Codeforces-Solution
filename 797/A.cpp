#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a;
  for (int i = 2; i <= n && k; i++) {
    while (!(n % i)) {
      n /= i;
      a.push_back(i);
      if (!--k) break;
    }
  }
  if (k) {
    puts("-1");
    return 0;
  }
  a.back() *= n;
  for (auto v : a) printf("%d ", v);
  puts("");
  return 0;
}