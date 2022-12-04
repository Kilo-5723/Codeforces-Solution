#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int solve(int s0l, int s1l, int s0r, int s1r, int v) { return v ? s0r : s1l; }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), s0(n + 1), s1(n + 1);
    ll base = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      s0[i + 1] = s0[i] + !a[i];
      s1[i + 1] = s1[i] + a[i];
      base += !a[i] * s1[i + 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(
          ans,
          solve(s0[i], s1[i], s0[n] - s0[i + 1], s1[n] - s1[i + 1], !a[i]) -
              solve(s0[i], s1[i], s0[n] - s0[i + 1], s1[n] - s1[i + 1], a[i]));
    printf("%lld\n", base + ans);
  }
  return 0;
}