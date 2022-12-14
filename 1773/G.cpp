#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5, buff = 20, exp = 1000;
char s[buff];
void fwt(vector<double> &a, int l = 0, int n = -1) {
  if (!~n) n = a.size();
  if (n == 1) return;
  int m = n / 2;
  fwt(a, l, m);
  fwt(a, l + m, m);
  for (int i = 0; i < m; i++) a[l + i] += a[l + m + i];
}
void ufwt(vector<double> &a, int l = 0, int n = -1) {
  if (!~n) n = a.size();
  if (n == 1) return;
  int m = n / 2;
  ufwt(a, l, m);
  ufwt(a, l + m, m);
  for (int i = 0; i < m; i++) a[l + i] -= a[l + m + i];
}
vector<double> vadd(vector<double> a, vector<double> b) {
  for (int i = 0; i < a.size(); i++) a[i] += b[i];
  return a;
}
vector<double> vmul(vector<double> a, vector<double> b) {
  for (int i = 0; i < a.size(); i++) a[i] *= b[i];
  return a;
}
int read(vector<double> &arr) {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<bitset<maxn>> a(m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    bool flg = true;
    for (int j = 0; j < m && flg; j++) flg = s[j] == '0';
    if (flg)
      for (int j = 0; j < m; j++) s[j] = '1';
    for (int j = 0; j < m; j++) a[j][i] = s[j] - '0';
  }
  for (int i = 1; i < m; i++) {
    if (a[0] == a[i]) {
      a.erase(a.begin() + i);
      i--;
      m--;
      continue;
    }
    if ((a[0] & a[i]) == a[0]) return -1;
  }
  m--;
  if (!m) return 1;
  // cout << m << endl;
  arr.assign(1 << m, 0);
  for (int i = 0; i < n; i++)
    if (a[0][i]) {
      int k = 0;
      for (int j = 1; j <= m; j++) k = k * 2 + a[j][i];
      arr[k] += 1.0 / n;
    }
  return 0;
}
int main() {
  vector<double> mul;
  auto tmp = read(mul);
  if (tmp) {
    puts(tmp == 1 ? "1" : "0");
    return 0;
  }
  fwt(mul);
  vector<vector<double>> pow = {mul};
  for (int i = 0; i < exp; i++) pow.push_back(vmul(pow.back(), pow.back()));
  vector<double> arr(mul.size(), 0);
  arr.back() = 1;
  fwt(arr);
  for (int i = exp; i >= 0; i--) arr = vadd(arr, vmul(arr, pow[i]));
  ufwt(arr);
  arr[0] = 0;
  fwt(arr);
  arr = vmul(arr, mul);
  ufwt(arr);
  printf("%.12f\n", arr[0]);
  return 0;
}