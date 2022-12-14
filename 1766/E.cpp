#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll method(int n) { return n * (n + 1LL) / 2; }
int main() {
  int n;
  scanf("%d", &n);
  ll ans = 0;
  vector<int> dp(12, 0);
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    int t;
    vector<int> nxt(12, 0);
    scanf("%d", &t);
    // cout << cnt << endl;
    switch (t) {
      case 0:
        ans += (i + 1LL) * (n - i);
        break;
      case 1:
        nxt[0] += cnt;
        ans += 1LL * cnt * (n - i);
        // 0 0
        nxt[0] += dp[0];
        // 1 7
        nxt[7] += dp[1];
        // 1
        ans += 1LL * dp[1] * (n - i);
        // 2 0
        nxt[0] += dp[2];
        // 3 3
        nxt[3] += dp[3];
        // 4 10
        nxt[10] += dp[4];
        // 4
        ans += 1LL * dp[4] * (n - i);
        // 5 3
        nxt[3] += dp[5];
        // 6 6
        nxt[6] += dp[6];
        // 7 7
        nxt[7] += dp[7];
        // 8 6
        nxt[6] += dp[8];
        // 9 9
        nxt[9] += dp[9];
        // 10 10
        nxt[10] += dp[10];
        // 11 9
        nxt[9] += dp[11];
        break;
      case 2:
        nxt[1] += cnt;
        ans += 1LL * cnt * (n - i);
        // 0 3
        nxt[3] += dp[0];
        // 0
        ans += 1LL * dp[0] * (n - i);
        // 1 1
        nxt[1] += dp[1];
        // 2 1
        nxt[1] += dp[2];
        // 3 3
        nxt[3] += dp[3];
        // 4 4
        nxt[4] += dp[4];
        // 5 4
        nxt[4] += dp[5];
        // 6 9
        nxt[9] += dp[6];
        // 6
        ans += 1LL * dp[6] * (n - i);
        // 7 7
        nxt[7] += dp[7];
        // 8 7
        nxt[7] += dp[8];
        // 9 9
        nxt[9] += dp[9];
        // 10 10
        nxt[10] += dp[10];
        // 11 10
        nxt[10] += dp[11];
        break;
      case 3:
        nxt[2] += cnt;
        ans += 1LL * cnt * (n - i);
        // 0 2
        nxt[2] += dp[0];
        // 1 2
        nxt[2] += dp[1];
        // 2 2
        nxt[2] += dp[2];
        // 3 5
        nxt[5] += dp[3];
        // 4 5
        nxt[5] += dp[4];
        // 5 5
        nxt[5] += dp[5];
        // 6 8
        nxt[8] += dp[6];
        // 7 8
        nxt[8] += dp[7];
        // 8 8
        nxt[8] += dp[8];
        // 9 11
        nxt[11] += dp[9];
        // 10 11
        nxt[11] += dp[10];
        // 11 11
        nxt[11] += dp[11];
        break;
    }
    if (t == 0)
      cnt++;
    else
      cnt = 1;
    dp = nxt;
  }
  printf("%lld\n", ans);
  return 0;
}
