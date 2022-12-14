#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1e6 + 5, lim = 4e4;
vector<int> mindiv(maxn);
vector<int> prime;
vector<int> divs(int n) {
  vector<int> res;
  for (auto v : prime) {
    if (n < v * v || v > lim) break;
    if (!(n % v)) {
      res.push_back(v);
      while (!(n % v)) n /= v;
    }
  }
  if (n > 1) res.push_back(n);
  return res;
}
int main() {
  for (int i = 1; i < maxn; i++) mindiv[i] = i;
  for (int i = 2; i < maxn; i++) {
    if (mindiv[i] == i) prime.push_back(i);
    for (int j = 0;
         j < prime.size() && prime[j] <= mindiv[i] && i * prime[j] < maxn; j++)
      mindiv[i * prime[j]] = prime[j];
  }
  // for (int i = 1; i < 100; i++) cout << i << ' ' << mindiv[i] << endl;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    set<int> st;
    bool flg = false;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      if (!flg)
        for (auto p : divs(t))
          if (st.count(p))
            flg = true;
          else
            st.insert(p);
    }
    puts(flg?"YES":"NO");
    // if (issame(a)) {
    //   puts("YES");
    //   continue;
    // }
    // cout << prime.size();
  }
  return 0;
}