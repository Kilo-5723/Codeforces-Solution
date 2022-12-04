#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
const int buff = 505;
char s[buff], t[buff];
int n, m;
bool eaq(char s[], char t[], int n) {
  // printf("%d ", n);
  // for (int i = 0; i < n; i++) putchar(s[i]);
  // putchar(' ');
  // for (int i = 0; i < n; i++) putchar(t[i]);
  // puts("");
  // puts("");
  for (int i = 0; i < n; i++)
    if (s[i] != t[i]) return false;
  return true;
}
int calc(char s[], int n, int p, bool b) {
  static char t[buff];
  for (int i = 0; i < p; i++) t[i] = s[i];
  t[p] = b + '0';
  for (int i = min(n, p + 1); i >= 0; i--)
    if (eaq(s, t + p + 1 - i, i)) return i;
  return -1;
}
typedef vector<vector<int>> arr;
arr go(const arr &dp, const arr &next, int b) {
  arr nxt(n + 1, vector<int>(m + 1, inf));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t = next[j][b];
      nxt[i][t] = min(nxt[i][t], dp[i][j]);
    }
    int t = next[m][b];
    nxt[i + 1][t] = min(nxt[i + 1][t], dp[i][m]);
  }
  return nxt;
}
arr add(const arr &a, const arr &b) {
  arr nxt(n + 1, vector<int>(m + 1));
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) nxt[i][j] = min(a[i][j], b[i][j] + 1);
  return nxt;
}
void write(const arr dp) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) printf("%d ", dp[i][j]);
    puts("");
  }
  puts("");
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s%s", s, t);
  vector<vector<int>> next;
  next.assign(m + 1, vector<int>(2));
  for (int i = 0; i <= m; i++) {
    next[i][0] = calc(t, m, i, 0);
    next[i][1] = calc(t, m, i, 1);
    // printf("%d %d\n", next[i][0], next[i][1]);
  }
  arr dp(n + 1, vector<int>(m + 1, inf));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    // printf("%d\n", i); 
    auto a = go(dp, next, s[i] - '0');
    auto b = go(dp, next, !(s[i] - '0'));
    dp = add(a, b);
    // write(dp);
  }
  for (int i = 0; i < n - m + 2; i++) {
    int ans = i ? dp[i - 1][m] : inf;
    for (int j = 0; j < m; j++) ans = min(ans, dp[i][j]);
    printf("%d ", ans > inf / 2 ? -1 : ans);
  }
  puts("");
  return 0;
}