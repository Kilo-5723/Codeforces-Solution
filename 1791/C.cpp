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
    vector<char> s(n + 1);
    scanf("%s", s.data());
    s.pop_back();
    int p = 0, q = n - 1;
    while (p < q && s[p] ^ s[q]) {
      p++;
      q--;
    }
    printf("%d\n", q - p + 1);
  }
  return 0;
}