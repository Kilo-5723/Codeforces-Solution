#include <cstdio>
#include <iostream>
using namespace std;
const int n = 3;
const char mod[] = "Yes";
const int buff = 1e5;
char s[buff];
bool check(char s[], int k) {
  for (int i = 0; s[i]; i++)
    if (s[i] != mod[(i + k) % n]) return false;
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    bool flg = false;
    for (int i = 0; i < 3 && !flg; i++) flg = check(s, i);
    puts(flg ? "YES" : "NO");
  }
  return 0;
}