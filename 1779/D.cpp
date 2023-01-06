#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    map<int, vector<int>, greater<int>> hair;
    map<int, vector<int>, greater<int>> nocut;
    map<int, int> cut;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int m;
    scanf("%d", &m);
    while (m--) {
      int t;
      scanf("%d", &t);
      cut[t]++;
    }
    bool flg = true;
    for (int i = 0; i < n; i++) {
      if (a[i] < b[i])
        flg = false;
      else if (a[i] > b[i])
        hair[b[i]].push_back(i);
      else
        nocut[b[i]].push_back(i);
    }
    set<int> finish;
    finish.insert(-1);
    while (hair.size()) {
      int x = hair.begin()->first;
      while (nocut.size() && nocut.begin()->first > x) {
        for (auto v : nocut.begin()->second) finish.insert(v);
        nocut.erase(nocut.begin());
      }
      int las = -2;
      int cnt = 0;
      for (auto v : hair.begin()->second) {
        if (finish.upper_bound(v) != finish.upper_bound(las)) cnt++;
        las = v;
      }
      for (auto v : hair.begin()->second) finish.insert(v);
      hair.erase(hair.begin());
      flg = flg && cnt <= cut[x];
    }
    puts(flg ? "YES" : "NO");
  }
  return 0;
}