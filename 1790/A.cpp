#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const char pi[] =
    "31415926535897932384626433832795028841971693993751058209749445923078164062"
    "862089986280348253421170679";
const int buff = 2e5;
char s[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    int p = 0;
    while (s[p] && s[p] == pi[p]) p++;
    printf("%d\n", p);
  }
  return 0;
}