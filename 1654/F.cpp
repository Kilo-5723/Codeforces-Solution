#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 1 << 19;
char s[buff];
vector<int> solve(char s[], int n) {
  vector<int> rnk(n);
  for (int i = 0; i < n; i++) rnk[i] = s[i] - 'a';
  for (int l = 1; (1 << l) <= n; l++) {
    vector<int> cnt(n);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  auto ans = solve(s, n);
  printf("%d\n", ans[0]);
  return 0;
}