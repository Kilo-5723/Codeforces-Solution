#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
struct fibo {
  int k;
  vector<ll> val;
  // fibo(int k, ll pos, ll tot) : k(k), pos(pos), tot(tot) {}
};
vector<fibo> stk;
fibo operator+(fibo a, fibo b) {
  a.k++;
  a.val.insert(a.val.end(), b.val.begin(), b.val.end());
  return a;
}
void push(fibo f) {
  while (stk.size() && stk.back().k == f.k + 1) {
    f = stk.back() + f;
    stk.pop_back();
  };
  // if (stk.size() && stk.back().k <= f.k) stk.clear();
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
      push(ch == '0' ? fibo{0, {las}} : fibo{1, {las}});
      las = (sum - stk.back().tot) % mod;
      sum = (sum + las) % mod;
      // for (auto v : stk) printf("fib: k = %d, v = %lld\n", v.k, v.tot);
      printf("sum = %lld, val = %lld, fib = %d\n", sum, las, stk.back().k);
    }
    printf("%lld\n", (las % mod + mod) % mod);
  }
  return 0;
}