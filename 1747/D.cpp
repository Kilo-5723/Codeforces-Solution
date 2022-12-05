#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int a[maxn], x[maxn];
ll s[maxn];
map<int, int> nxt;
map<int, vector<int>> stk;
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  stk[0].push_back(0);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s[i + 1] = s[i] + a[i];
    x[i + 1] = x[i] ^ a[i];
    int k = x[i + 1];
    if (!stk.count(k) || (stk[k].back() - i & 1))
      stk[k].push_back(i + 1);
    else {
      for (auto p : stk[k]) nxt[p] = i + 1;
      stk[k] = {i + 1};
    }
    // cz[i + 1] = cz[i] + (a[i] == 0);
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (!(s[r] - s[l - 1])) {
      puts("0");
      continue;
    }
    if (x[r] ^ x[l - 1]) {
      puts("-1");
      continue;
    }
    if (!(r - l & 1)) {
      puts("1");
      continue;
    }
    if (!a[l - 1] || !a[r - 1]) {
      puts("1");
      continue;
    }
    if (nxt.count(l - 1) && nxt[l - 1] < r) {
      puts("2");
      continue;
    }
    puts("-1");
  }
  return 0;
}