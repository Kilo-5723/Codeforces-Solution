#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int week = 7;
map<string, int> day = {{"Monday", 1},   {"Tuesday", 2}, {"Wednesday", 3},
                        {"Thursday", 4}, {"Friday", 5},  {"Saturday", 6},
                        {"Sunday", 0}

};
const int buff = 100;
char s[buff];
int readint() {
  char ch = getchar();
  int res = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res;
}
int read() {
  int p = 0;
  char ch = getchar();
  while (ch == ' ') ch = getchar();
  while (ch >= 'A' && ch <= 'z') {
    s[p++] = ch;
    ch = getchar();
  }
  s[p] = 0;
  string str = s;
  return day[str];
}
int main() {
  int n = readint();
  int m = readint();
  int k = readint();
  vector<vector<int>> available(week);
  vector<vector<bool>> canwork(n, vector<bool>(7, false));
  for (int e = 0; e < n; e++) {
    int t = readint();
    while (t--) {
      int q = read();
      available[q].push_back(e);
      canwork[e][q] = true;
    }
  }
  vector<int> holiday(m);
  for (int h = 0; h < m; h++) holiday[h] = readint();
  reverse(holiday.begin(), holiday.end());
  vector<vector<int>> project(k);
  for (auto &arr : project) {
    int t = readint();
    arr.resize(t);
    for (int i = 0; i < t; i++) arr[i] = readint();
    for (auto &v : arr) v--;
    reverse(arr.begin(), arr.end());
  }
  vector<set<int>> work(n);
  vector<set<int>> busy(week);
  for (int p = 0; p < k; p++) {
    int e = project[p].back();
    work[e].insert(p);
    for (int d = 0; d < 7; d++)
      if (canwork[e][d]) busy[d].insert(e);
  }
  int res = k;
  vector<int> ans(k);
  for (int td = 1; res; td++) {
    if (td == holiday.back()) {
      holiday.pop_back();
      continue;
    }
    // cout << d << ' ' << res << endl;
    vector<pair<int, int>> dotoday;
    for (auto e : busy[td % week])
      if (canwork[e][td % week]) dotoday.push_back({e, *work[e].begin()});
    for (auto [e, p] : dotoday) {
      work[e].erase(p);
      if (!work[e].size())
        for (int d = 0; d < 7; d++)
          if (canwork[e][d]) busy[d].erase(e);
      project[p].pop_back();
      if (!project[p].size()) {
        ans[p] = td;
        res--;
        continue;
      }
      int ep = project[p].back();
      work[ep].insert(p);
      for (int d = 0; d < 7; d++)
        if (canwork[ep][d]) busy[d].insert(ep);
    }
  }
  for (auto v : ans) printf("%d ", v);
  puts("");
  return 0;
}