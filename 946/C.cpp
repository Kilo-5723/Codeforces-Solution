#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 2e5;
char s[buff];
int main() {
  scanf("%s", s);
  int p = 0;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    while (s[p] && s[p] > ch) p++;
    if (!s[p]) {
      puts("-1");
      return 0;
    }
    s[p++] = ch;
  }
  printf("%s\n", s);
  return 0;
}