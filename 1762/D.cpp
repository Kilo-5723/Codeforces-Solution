#include <cstdio>
#include <iostream>
#include <random>
#include <set>
using namespace std;
int query(int x, int y) {
  cout << "? " << x << ' ' << y << endl;
  int t;
  cin >> t;
  return t;
}
int submit(int x, int y) {
  cout << "! " << x << ' ' << y << endl;
  int t;
  cin >> t;
  return t;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int x = 1, y = 2;
    for (int i = 3; i <= n; i++) {
      int p = query(x, i), q = query(y, i);
      if (p < q) x = i;
      if (p > q) y = i;
    }
    submit(x, y);
  }
  return 0;
}