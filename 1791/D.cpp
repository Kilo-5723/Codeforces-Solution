#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int alpha = 26;
int calc(vector<int> &cnt, vector<int> &tot) {
  int res = 0;
  for (int i = 0; i < alpha; i++) res += (bool)cnt[i] + bool(tot[i] - cnt[i]);
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> tot(alpha), cnt(alpha);
    vector<char> s(n + 1);
    scanf("%s", s.data());
    s.pop_back();
    for (auto ch : s) tot[ch - 'a']++;
    int ans = 0;
    for (auto ch : s) {
      cnt[ch - 'a']++;
      ans = max(ans, calc(cnt, tot));
    }
    printf("%d\n", ans);
  }
  return 0;
}