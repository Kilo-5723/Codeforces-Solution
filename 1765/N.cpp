#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
const int maxn = 5e5 + 5;
char s[maxn], t[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    int p = 0;
    for (int i = 1; i <= k; i++)
      if (s[i] < s[p] && s[i] != '0') p = i;
    int m = 0;
    t[m++] = s[p];
    set<pair<char, int>> st;
    for (int i = p + 1; i <= k; i++) st.insert({s[i], i});
    p = k + 1;
    while (s[p]) {
      st.insert({s[p], p});
      auto [ch, pos] = *st.begin();
      t[m++] = ch;
      for (int i = pos; i >= 0 && st.count({s[i], i}); i--) st.erase({s[i], i});
      p++;
    }
    t[m] = 0;
    printf("%s\n", t);
  }
  return 0;
}