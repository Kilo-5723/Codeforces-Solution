#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long double ld;
const int buff = 1e3;
char s[buff];
int read() {
  scanf("%s", s);
  int res = 0;
  for (int i = 0; s[i]; i++) res = res * 2 + s[i] - '0';
  return res;
}
void fwt(vector<int> &a, int l, int n) {
  if (n == 1) return;
  int m = n / 2;
  fwt(a, l, m);
  fwt(a, l + m, m);
  for (int i = 0; i < m; i++) a[l + i] += a[l + m + i];
}
int lowbit(int n) { return n & -n; }
vector<int> gen(int bin) {
  vector<int> res;
  while (bin) {
    res.push_back(lowbit(bin));
    bin -= lowbit(bin);
  }
  return res;
}
ld solve(int a, vector<int> &b, int bin, int eff, int msk, vector<ld> &mem) {
  if ((a & eff) != eff) return 0;
  if (!b[eff]) return mem[eff] = 1;
  // if (mem[eff] > -1) return mem[eff];
  auto arr = gen(msk & ~bin);
  if (!arr.size()) return mem[eff] = 1;
  double res = 0, mul = 1.0 / arr.size();
  for (auto v : arr) {
    if ((a & v) !=  v && !b[eff + v])
      res += solve(a, b, bin + v, eff, msk, mem);
    else
      res += solve(a, b, bin + v, eff + v, msk, mem);
  }
  return mem[eff] = res * mul;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a = read();
  vector<int> b(1 << m);
  for (int i = 1; i < n; i++) b[read()]++;
  fwt(b, 0, 1 << m);
  vector<ld> mem(1 << m, -2);
  printf("%.12Lf\n", solve(a, b, 0, 0, (1 << m) - 1, mem));
  return 0;
}