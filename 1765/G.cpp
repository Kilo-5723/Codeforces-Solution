#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
void dfs(int u, int k, vector<int>& a, vector<vector<pair<int, int>>>& e) {
  if (~a[u]) return;
  a[u] = k;
  for (auto [v, w] : e[u]) dfs(v, k ^ w, a, e);
}
int main() {
  srand(time(0));
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n, -1);
    vector<vector<pair<int, int>>> e(n);
    cout << "2 2" << endl;
    int f;
    cin >> f;
    while (n > 2) {
      int t = (rand() & 1);
      cout << 1 + t << ' ' << n << endl;
      int x;
      cin >> x;
      if (!x) {
        e[0].push_back({n - 1, !t});
        if (f) {
          e[n - 1].push_back({n - 2, 0});
          n--;
        }
        n--;
      } else if (x == 1) {
        e[0].push_back({n - 1, t});
        if (!f) {
          e[n - 1].push_back({n - 2, 1});
          n--;
        }
        n--;
      } else {
        for (int i = 0; i < x; i++) e[i].push_back({n - x + i, t});

        n -= x;
      }
    }
    dfs(0, 0, a, e);
    dfs(1, f, a, e);
    cout << "0 ";
    for (auto v : a) cout << v;  // putchar('0' + v);
    cout << endl;
    int t;
    cin >> t;
  }
  return 0;
}