#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 2e5;
const int inf = 1e9, alpha = 26;
char s[buff];
int calc(vector<int> &arr, int k, int v) {
  int res = 0;
  for (int i = 0; i < k; i++) res += min(v, arr[i]);
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    vector<int> cnt(alpha);
    for (int i = 0; s[i]; i++) cnt[s[i] - 'a']++;
    auto arr = cnt;
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    int ans = 0, p = -1;
    for (int i = 1; i <= alpha; i++)
      if (!(n % i)) {
        int res = calc(arr, i, n / i);
        if (res > ans) {
          ans = res;
          p = i;
        }
      }
    printf("%d\n", n - ans);
    int k = n / p;
    vector<int> ord(alpha);
    for (int i = 0; i < alpha; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i, int j) { return cnt[i] > cnt[j]; });
    vector<int> pos(alpha);
    for (int i = 0; i < alpha; i++) pos[ord[i]] = i;
    // for (auto v : ord) cout << v << ' ';
    // cout << endl;
    for (int i = 0; s[i]; i++) {
      int c = s[i] - 'a';
      if (pos[c] < p && cnt[c] <= k) {
        putchar(s[i]);
        continue;
      }
      for (int j = 0; j < alpha; j++)
        if (pos[j] < p && cnt[j] < k) {
          putchar('a' + j);
          cnt[j]++;
          break;
        }
      cnt[c]--;
    }
    puts("");
  }
  return 0;
}