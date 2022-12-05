#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 2e5 + 5;
char s[buff];
int main() {
  scanf("%s", s);
  for (int i = 1; s[i]; i++)
    if (s[i] == s[i - 1]) s[i] = '-';
  for (int i = 1; s[i]; i++)
    if (s[i] == '-') {
      s[i] = 'a';
      while (s[i] == s[i - 1] || s[i] == s[i + 1]) s[i]++;
    }
  printf("%s\n",s);
  return 0;
}