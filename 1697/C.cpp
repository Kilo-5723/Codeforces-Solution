#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 2e5;
char s[buff], t[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    bool flg = true;
    int p = 0, q = 0;
    while (p < n && q < n) {
      while (p < n && s[p] == 'b') p++;
      while (q < n && t[q] == 'b') q++;
      if (s[p++] != t[q++]) {
        flg = false;
        break;
      }
    }
    vector as(3, vector<int>()), at(3, vector<int>());
    for (int i = 0; i < n; i++) as[s[i] - 'a'].push_back(i);
    for (int i = 0; i < n; i++) at[t[i] - 'a'].push_back(i);
    if (as[0].size() != at[0].size() || as[2].size() != at[2].size()) {
      flg = false;
    } else {
      for (int i = 0; i < as[0].size(); i++) flg = flg && as[0][i] <= at[0][i];
      for (int i = 0; i < as[2].size(); i++) flg = flg && as[2][i] >= at[2][i];
    }
    puts(flg ? "YES" : "NO");
  }
  return 0;
}