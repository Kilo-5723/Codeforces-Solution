#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int buff = 105;
char s[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    printf("%s", s);
    reverse(s, s + strlen(s));
    printf("%s\n", s);
  }
  return 0;
}