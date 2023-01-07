#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 1e5;
char s[buff];
int solve(char s[]) {
  for (int i = 1; s[i]; i++) {
    if (s[i - 1] == 'R' && s[i] == 'L') return 0;
    if (s[i - 1] == 'L' && s[i] == 'R') return i;
  }
  return -1;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    printf("%d\n", solve(s));
  }
  return 0;
}