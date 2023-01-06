#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

#include <cstdio>
#include <iostream>
#define N 1000005
using namespace std;
int n;
ll phi[N + 10], prime[N + 10], tot, ans;
bool mark[N + 10];
void getphi() {
  int i, j;
  phi[1] = 1;
  for (i = 2; i <= N; i++) {
    if (!mark[i]) {
      prime[++tot] = i;
      phi[i] = i - 1;
    }
    for (j = 1; j <= tot; j++) {
      if (i * prime[j] > N) break;
      mark[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
    }
  }
}
int main() {
  getphi();
  phi[1]--;
  for (int i = 1; i < N; i++) phi[i] += phi[i - 1];
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll ans = 0;
    for (int k = n - 1; k >= 1; k--) {
      ll t = phi[n / (k + 1)] / k;
      t = min(t, m / k);
      m -= t * k;
      ans += t * (k + 1);
    }
    if (m) {
      puts("-1");
      continue;
    }
    printf("%lld\n", ans);
  }
  return 0;
}