#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 205;
int calc(string s) {
  int res = 0;
  for (auto ch : s)
    if (ch < 'a') res++;
  return res;
}
int main() {
  int n;
  cin >> n;
  int ans = 0;
  string s;
  while (cin >> s) ans = max(ans, calc(s));
  cout << ans << endl;
  return 0;
}