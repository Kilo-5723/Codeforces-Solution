#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5, maxm = 1e6 + 5;
int n;
int a[maxn], ord[maxn];
int f[maxn], visl[maxn], visr[maxn];
int lessl[maxn], lessr[maxn], morel[maxn], morer[maxn];
int ff(int u) { return u == f[u] ? u : f[u] = ff(f[u]); }
void comb(int u, int v) {
  u = ff(u);
  v = ff(v);
  f[u] = v;
  visl[v] = min(visl[v], visl[u]);
  visr[v] = max(visr[v], visr[u]);
}
bool check(int a1, int a2, int b) { return b ? a1 <= a2 : a1 >= a2; }
void merge(int u, bool b) {
  if (u > 0 && check(a[u], a[u - 1], b)) comb(u, u - 1);
  if (u < n - 1 && check(a[u], a[u + 1], b)) comb(u, u + 1);
}
vector<int> pos[maxm];
ll calc(int u, int v, int rb) {
  int l = max(morel[u], lessl[v]), r =  min(morer[u], lessr[v]);
  if (u > v) swap(u, v);
  if (l > u || r < v) return 0;
  return (ll)(u - l + 1) * (r - v + 1);
}
ll solve(const vector<int> &a, const vector<int> &b) {
  int rb = maxn;
  ll ans = 0;
  int p = a.size(), q = b.size();
  while (p && q) {
    ans += calc(a[p - 1], b[q - 1], rb);
    if (a[p - 1] > b[q - 1])
      rb = a[--p] - 1;
    else
      rb = b[--q] - 1;
  }
  // printf("%lld\n", ans);
  return ans;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord, ord + n, [](int x, int y) { return a[x] < a[y]; });
    for (auto flg : {false, true}) {
      for (int i = 0; i < n; i++) {
        f[i] = i;
        visl[i] = i;
        visr[i] = i;
      }
      int l, r;
      for (l = 0; l < n; l = r) {
        r = l;
        while (r < n && a[ord[r]] == a[ord[l]]) r++;
        for (int i = l; i < r; i++) merge(ord[i], flg);
        for (int i = l; i < r; i++) {
          (flg ? morel[ord[i]] : lessl[ord[i]]) = visl[ff(ord[i])];
          (flg ? morer[ord[i]] : lessr[ord[i]]) = visr[ff(ord[i])];
        }
      }
      reverse(ord, ord + n);
    }
    // for (int i = 0; i < n; i++)
    //   printf("%d %d %d %d\n", lessl[i], lessr[i], morel[i], morer[i]);
    for (int i = 0; i < maxm; i++) pos[i].clear();
    for (int i = 0; i < n; i++) pos[a[i]].push_back(i);
    for (int i=0;i<maxm;i++) {
      for (int j=1;j<pos[i].size();j++){
        // lessl[pos[i][j]]=max(lessl[pos[i][j]],pos[i][j-1]+1);
        // morel[pos[i][j]]=max(morel[pos[i][j]],pos[i][j-1]+1);
        // lessr[pos[i][j-1]]=min(lessr[pos[i][j-1]],pos[i][j]-1);
        // morer[pos[i][j-1]]=min(morer[pos[i][j-1]],pos[i][j]-1);
      }
    }
    ll ans = 0;
    for (int i = 1; i < maxm; i++)
      if (pos[i].size()) {
        vector<int> arr;
        for (int j = 2 * i; j < maxm; j += i)
          if (pos[j].size()) {
            for (auto v : pos[j]) arr.push_back(v);
            // printf("%d %d\n", i, j);
            // ans += solve(pos[i], pos[j]);
          }
        sort(arr.begin(), arr.end());
        ans += solve(pos[i], arr);
      }
    // printf("%lld\n", ans);
    int las = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != las) {
        ans += 1LL * cnt * (cnt + 1) / 2;
        las = a[i];
        cnt = 1;
      } else {
        cnt++;
      }
    }
    ans += 1LL * cnt * (cnt + 1) / 2;
    printf("%lld\n", ans);
  }
  return 0;
}