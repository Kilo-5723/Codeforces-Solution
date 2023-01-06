#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
const int buff = 6e3;
char s[buff], t[buff];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int m, n;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    scanf("%s", t);
    vector dpl(n + 1, vector<int>(m + 1, inf));
    vector avr(n + 1, vector<bool>(m + 1, false));
    vector len(n + 1, vector<int>(m + 1, -inf));
    dpl[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      dpl[i][0] = i;
      for (int j = 1; j <= i && j <= m; j++) {
        dpl[i][j] = dpl[i - 1][j] + 1;
        if (s[i - 1] == t[j - 1]) dpl[i][j] = min(dpl[i][j], dpl[i - 1][j - 1]);
      }
    }
    avr[n][m] = true;
    for (int i = n - 1; i >= 0; i--) {
      avr[i][m] = true;
      for (int j = m - 1; j >= 0 && m - j <= n - i; j--) {
        avr[i][j] = avr[i + 1][j];
        if (s[i] == t[j]) avr[i][j] = avr[i][j] || avr[i + 1][j + 1];
      }
    }
    len[n][m] = 0;
    for (int i = n - 1; i >= 0; i--) {
      len[i][m] = 0;
      for (int j = m - 1; j >= 0 && m - j <= n - i; j--) {
        if (!avr[i][j]) continue;
        len[i][j] = 0;
        if (s[i] == t[j]) len[i][j] = len[i + 1][j + 1] + 1;
      }
    }
    int ans = n - len[0][0];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= i && j <= m; j++) {
        ans = min(ans, n + dpl[i][j] - len[i][j] + 1);
      }
    printf("%d\n", ans < inf / 2 ? ans : -1);
  }
  return 0;
}