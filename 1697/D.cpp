#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
char query1(int a) {
  cout << "? 1 " << a + 1 << endl;
  string s;
  cin >> s;
  return s[0];
}
int query2(int a, int b) {
  cout << "? 2 " << a + 1 << ' ' << b + 1 << endl;
  int n;
  cin >> n;
  return n;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> last;
  for (int i = 0; i < n; i++) {
    int l = -1, r = last.size();
    while (r - l > 1) {
      int m = (l + r) / 2;
      auto [p, v] = last[m];
      int res = query2(p, i);
      if (res == last.size() - m)
        l = m;
      else
        r = m;
    }
    if (l == -1) {
      a[i] = last.size();
      last.push_back({i, a[i]});
    } else {
      a[i] = last[l].second;
      last.erase(last.begin() + l);
      last.push_back({i, a[i]});
    }
  }
  vector<char> s(last.size());
  for (auto [p, v] : last) s[v] = (query1(p));
  cout << "! ";
  for (auto v : a) cout << s[v];
  cout << endl;
  return 0;
}