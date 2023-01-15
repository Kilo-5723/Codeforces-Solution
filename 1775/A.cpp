#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 1e6;
char s[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    int n = strlen(s);
    vector<int> a;
    int cnt = 0;
    for (int i = 1; s[i]; i++) cnt += s[i] != s[i - 1];
    if (!cnt) {
      printf("%c %s %c\n", s[0], s + 2, s[0]);
      continue;
    }
    if (cnt == 1) {
      if (s[0] == s[1]) {
        printf("%c %c %s\n", s[0], s[0], s + 2);
      } else {
        s[n - 2] = 0;
        printf("%s %c %c\n", s, s[n - 1], s[n - 1]);
      }
      continue;
    }
    int p = 0;
    while (s[p] == s[0]) p++;
    int q = p;
    while (s[q] == s[p]) q++;
    char ch = 0;
    swap(ch, s[p]);
    printf("%s ", s);
    swap(ch, s[p]);
    swap(ch, s[q]);
    printf("%s ", s + p);
    swap(ch, s[q]);
    printf("%s\n", s + q);
  }
  return 0;
}