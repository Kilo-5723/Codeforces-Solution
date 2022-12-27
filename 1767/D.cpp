#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 1e5;
char s[buff];
int main() {
  int n;
  scanf("%d", &n);
  int a = 0, b = 0;
  scanf("%s", s);
  for (int i = 0; s[i]; i++)
    if (s[i] == '1')
      b++;
    else
      a++;
  for (int i = (1 << b); i <= (1 << n) + 1 - (1 << a); i++) printf("%d ", i);
  puts("");
  return 0;
}