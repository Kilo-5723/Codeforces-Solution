#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 2e6, alpha = 26;
char s[buff];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  vector<int> next(n + 1);
  vector<vector<int>> trans(n + 1, vector<int>(26));
  next[0] = -1;
  for (int i = 0; i < n; i++) {
    int j = next[i];
    while (~j && s[j] != s[i]) j = next[j];
    next[i + 1] = ~j ? j + 1 : 0;
    for (int k = 0; k < alpha; k++) {
      trans[i][k] = s[i] == 'a' + k ? i + 1 : trans[max(next[i], 0)][k];
      // cout << trans[i][k] << ' ';
    }
    // cout << endl;
  }
  // for (int i = 0; i <= n; i++) printf("%d ", next[i]);
  // puts("");
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s + n);
    int m = strlen(s + n) + n;
    next.resize(m + 1);
    for (int i = n; i < m; i++) {
      int j = next[i];
      while (~j && s[j] != s[i]) {
        // cout << j << endl;
        if (j > n - 1)
          j = next[j];
        else
          j = trans[j][s[i] - 'a'] - 1;
      }
      next[i + 1] = ~j ? j + 1 : 0;
      printf("%d ", next[i + 1]);
    }
    puts("");
  }
  return 0;
}