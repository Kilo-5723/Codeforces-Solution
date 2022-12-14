#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int alpha = 26, buff = 2e5 + 5;
char s[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    if (n > 2 * alpha * alpha) {
      puts("YES");
      continue;
    }
    set<pair<char, char>> st;
    bool flg = false;
    for (int i = 1; i < n; i++) {
      if (st.count({s[i - 1], s[i]})) flg = true;
      if (i > 1) st.insert({s[i - 2], s[i - 1]});
    }
    puts(flg ? "YES" : "NO");
  }
  return 0;
}