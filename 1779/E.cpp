#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int submit(int i, string s) {
  cout << "? " << i + 1 << ' ' << s << endl;
  int res;
  cin >> res;
  return res;
}
int main() {
  int n;
  cin >> n;
  string s(n, '1');
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    s[i] = '0';
    a[i] = submit(i, s);
    s[i] = '1';
  }
  vector<int> ord(n);
  for (int i = 0; i < n; i++) ord[i] = i;
  sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] > a[j]; });
  int las = 0;
  s.assign(n, '0');
  s[ord[0]] = '1';
  for (int i = 1; i < n; i++)
    if (submit(ord[i], s)) {
      for (int j = las + 1; j <= i; j++) s[ord[j]] = '1';
      las = i;
    }
  cout << "! " << s << endl;
  return 0;
}