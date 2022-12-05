#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 2e5 + 5;
char s[buff];
void solve(int x, int &a, int &b) {
  if (a < b) swap(a, b);
  a -= min(a, (x + 1) / 2), b -= min(b, x / 2);
}
int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  scanf("%s", s);
  int c = a + b;
  for (int i = 0; s[i]; i++) {
    int j = i;
    while (s[j] == '.') j++;
    solve(j - i, a, b);
    i = j;
  }
  printf("%d\n", c - a - b);
  return 0;
}