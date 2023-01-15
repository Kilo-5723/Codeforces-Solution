#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int buff = 2e6;
const char opr[] = "<=>";
char s[buff], t[buff];
int main() {
  string s, t;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  while (s.size() < t.size()) s.push_back('0');
  while (s.size() > t.size()) t.push_back('0');
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  if (s < t) puts("<");
  if (s == t) puts("=");
  if (s > t) puts(">");
  return 0;

  return 0;
}