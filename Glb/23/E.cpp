#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int lay = 17;
int n;
vector<int> arr;
int submit(int m) {
  if (m < 1 || m > n) return 0;
  cout << "! " << m << endl;
  cout.flush();
  string s;
  cin >> s;
  return s[1] == ')';
}
int query(int m) {
  vector<int> arr;
  for (int i = 1; i <= n; i++)
    if ((i >> m) & 1) arr.push_back(i);
  if (!arr.size()) return 0;
  cout << "? " << arr.size();
  for (auto v : arr) cout << ' ' << v;
  cout << endl;
  cout.flush();
  string s;
  cin >> s;
  return s[0] == 'Y';
}
int c[lay], e[lay], f[lay];
int fv(int u) { return (u == f[u]) ? c[u] : (e[u] ^ fv(f[u])); }
int main() {
  cin >> n;
  for (int i = 0; i < lay; i++) {
    arr.push_back(i);
    f[i] = i;
  }
  while (arr.size() > 1) {
    vector<int> brr;
    int las = -1, lval = 0;
    for (auto v : arr) {
      int a = query(v);
      int b = query(v);
      if (a == b) {
        c[v] = a;
        las = -1;
      } else if (las != -1) {
        f[v] = las;
        e[v] = a ^ lval;
      } else {
        brr.push_back(v);
        las = v;
        lval = a;
      }
    }
    arr = brr;
  }
  int ans = 0;
  for (int i = 0; i < lay; i++) ans += (fv(i) << i);
  if (submit(ans)) return 0;
  c[arr[0]] ^= 1;
  ans = 0;
  for (int i = 0; i < lay; i++) ans += (fv(i) << i);
  submit(ans);
  return 0;
}