#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 3e5;
char s[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    scanf("%s", s);
    for (int i = 0; s[i]; i++)
      if (s[i] == '*') a[i]++;
    scanf("%s", s);
    for (int i = 0; s[i]; i++)
      if (s[i] == '*') a[i] += 2;
    int flg = false, cur = 0, ans = 0;
    while (!a.back()) a.pop_back();
    for (int i = 0; i < a.size(); i++) {
      ans += flg;
      if (!a[i]) continue;
      if (a[i] == 3) ans++;
      if (!flg) {
        flg = true;
        cur = a[i];
        continue;
      }
      if (cur == a[i]) continue;
      if (cur == 3) {
        cur = a[i];
        continue;
      }
      if (a[i] == 3) {
        cur = 3;
        continue;
      }
      cur = 3;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}