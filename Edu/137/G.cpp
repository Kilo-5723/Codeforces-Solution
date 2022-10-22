#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
struct fibo {
  int k;
  ll tot;
  vector<ll> val;
  bool flg;
};
vector<fibo> stk;
fibo operator+(fibo a, fibo b) {
  fibo c{a.k + 1, (a.val.back() + b.tot) % mod, b.val};
  // c.val.insert(c.val.end(), b.val.begin(), b.val.end());
  c.val.push_back(a.val.back());
  return c;
}
void push(fibo f) {
  while (stk.size() && stk.back().k == f.k + 1) {
    f = stk.back() + f;
    stk.pop_back();
  };
  if (stk.size() && stk.back().k <= f.k) stk.clear();
  stk.push_back(f);
}
int main() {
  int n;
  scanf("%d", &n);
  char ch = getchar();
  ll sum = 1, las = 1;
  while (n--) {
    while ((ch = getchar()) != '\n') {
      // putchar(ch);
      push(ch == '0' ? fibo{0, las, {las}} : fibo{1, las, {las}});
      las = (sum - stk.back().tot) % mod;
      // printf("found %d", stk.back().k);
      if (stk.size() > 1) {
        auto &nxt = stk[stk.size() - 2], &bot = stk.back();
        if ((nxt.k - bot.k) & 1) {
          las = (las - nxt.val[(bot.k + 1) / 2]) % mod;
          // printf(" and %d", stk.back().k + 2);
        }
      }
      // puts("");
      sum = (sum + las) % mod;
      // for (auto v : stk) printf("fib: k = %d, v = %lld\n", v.k, v.tot);
      // printf("sum = %lld, val = %lld, fib = %d\n", sum, las, stk.back().k);
    }
    printf("%lld\n", (las % mod + mod) % mod);
  }
  return 0;
}