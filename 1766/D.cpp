#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e7 + 5;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
vector<int> mindiv(maxn), prime;
// vector<vector<int>> pdiv(maxn);
vector<int> pdiv(int n) {
  vector<int> res;
  while (n > 1) {
    res.push_back(mindiv[n]);
    while (!(n % res.back())) n /= res.back();
  }
  return res;
}
int main() {
  for (int i = 1; i < maxn; i++) mindiv[i] = i;
  for (int i = 2; i < maxn; i++) {
    // if (!pdiv[i].size()) {
    //   for (int j = i; j < maxn; j += i) pdiv[j].push_back(i);
    if (mindiv[i] == i) prime.push_back(i);
    for (auto v : prime) {
      if (v > mindiv[i] || i * v >= maxn) break;
      mindiv[i * v] = v;
    }
  }
  // for (int i = 0; i < 100; i++) {
  //   for (auto v : pdiv[i]) cout << v << ' ';
  //   cout << endl;
  // }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == y - 1) {
      puts("-1");
      continue;
    }
    int ans = maxn;
    for (auto v : pdiv(y - x)) ans = min(ans, (v - x % v) % v);
    printf("%d\n", ans);
    // for *
  }
  return 0;
}