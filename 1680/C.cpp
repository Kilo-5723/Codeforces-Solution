#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn];
bool check(char s[], const vector<int> &a, int n, int m) {
  int cnt = 0;
  for (int l = 0, r = 0; r < n; l++) {
    while (r < n && cnt + (s[r] == '0') <= m) cnt += (s[r++] == '0');
    if (a[l] + a.back() - a[r] <= m) return true;
    cnt -= (s[l] == '0');
  }
  return false;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    int n = strlen(s);
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) a[i + 1] = a[i] + (s[i] == '1');
    int l = -1, r = n;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (check(s, a, n, m))
        r = m;
      else
        l = m;
    }
    printf("%d\n", r);
  }
  return 0;
}