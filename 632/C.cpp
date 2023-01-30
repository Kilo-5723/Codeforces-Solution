#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end(),
       [](const string &a, const string &b) { return a + b < b + a; });
  for (auto s : a) cout << s;
  cout << endl;
  return 0;
}