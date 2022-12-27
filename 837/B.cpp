#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int buff = 200;
char s[buff];
bool check(vector<vector<char>> a) {
  int n = a.size(), m = n / 3;
  if (n % 3) return false;
  for (auto &arr : a)
    for (auto v : arr)
      if (v != arr.back()) return false;
  for (int i = 1; i < n; i++)
    if ((i % m > 0) != (a[i] == a[i - 1])) return false;
  if (a[m * 2] == a[0]) return false;
  return true;
}
vector<vector<char>> flip(vector<vector<char>> a) {
  int n = a.size(), m = a[0].size();
  vector b(m, vector<char>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) b[j][i] = a[i][j];
  return b;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) a[i][j] = s[j];
  }
  puts(check(a) || check(flip(a)) ? "YES" : "NO");
  return 0;
}