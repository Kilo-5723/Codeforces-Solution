#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 2e3 + 5;
int cnt[maxn];
int stk[maxn];
vector<int> arr;
vector<vector<ll>> res;
// vector<ll> pre;
void push_back(int k, int cnt) {
  // printf("%d\n", k);
  // k++;
  vector<ll> arr(maxn);
  for (int i = k; i <= res.size(); i++) {
    arr[i] =
        (arr[i - 1] + res[res.size() - i][i] - res[res.size() - i][cnt - 1]) %
        mod;
    // if (arr[i]) printf("%d %d %lld\n", k, i, arr[i]);
  }
  for (int i = res.size() + 1; i < maxn; i++) arr[i] = arr[i - 1];
  res.push_back(arr);
}
int main() {
  int n;
  scanf("%d", &n);
  arr = {};
  res.resize(1);
  res[0].assign(maxn, 1);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    cnt[t]++;
  }
  for (int i = 1; i <= n; i++) {
    int t = cnt[i];
    // printf("cnt %d: %d\n", i, cnt[i]);
    while (t--) stk[t]++;
  }
  // for (int i = 0; i < n; i++) printf("%d\n", stk[i]);
  for (int i = 0; i < n; i++)
    if (stk[i]) arr.push_back(stk[i]);
  // reverse(arr.begin(), arr.end());
  int k = 1, add = 0;
  int cnt = 0;
  for (auto v : arr) {
    // printf("v: %d\n", v);
    bool flg = true;
    while (v--) {
      push_back(k, cnt);
      cnt += flg;
      flg = false;
      // k += add;
    }
    k++;
    // add++;
  }
  printf("%lld\n", (res.back().back() % mod + mod) % mod);
  // puts("");
  return 0;
}