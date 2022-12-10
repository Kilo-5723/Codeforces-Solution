#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1.1e8 + 1, step = 30;
void read(int &x, int &y) {
  scanf("%d%d", &x, &y);
  x += step;
  y--;
}
struct chess {
  char t;
  int x, y;
};
const int buff = 100;
char s[buff];
chess read() {
  chess a;
  scanf("%s", s);
  a.t = s[0];
  read(a.x, a.y);
  return a;
}
void visit(int x, vector<int> &proj) {
  for (int k = -step; k <= step; k++)
    if (x + k > 0 && x + k < proj.size()) proj[x + k] = 1;
}
bool legal(vector<vector<int>> &dis, int x, int y) {
  if (x < 0 || x >= dis.size()) return false;
  if (y < 0 || y >= dis[0].size()) return false;
  return true;
}
bool setno(vector<vector<int>> &dis, int x, int y, int v) {
  if (!legal(dis, x, y)) return false;
  if (dis[x][y] == -3) return false;
  dis[x][y] = v;
  return true;
}
struct pos {
  int d, x, y;
};
bool operator<(pos a, pos b) { return a.d > b.d; }
int bfs(vector<vector<int>> &dis, vector<int> ox, int xs, int ys, int xt,
        int yt) {
  priority_queue<pos> que;
  que.push({0, xs, ys});
  while (que.size()) {
    auto [d, x, y] = que.top();
    que.pop();
    if (dis[x][y] >= 0 && d >= dis[x][y]) continue;
    dis[x][y] = d;
    for (auto dx : {-1, 0, 1})
      for (auto dy : {-1, 0, 1})
        if (legal(dis, x + dx, y + dy) && dis[x + dx][y + dy] >= -1)
          que.push(
              {d + 1 + (dx ? abs(ox[x + dx] - ox[x]) - 1 : 0), x + dx, y + dy});
  }
  return dis[xt][yt];
}
int main() {
  vector<int> proj(maxn, 0);
  int xs, ys, xt, yt;
  read(xs, ys);
  visit(xs, proj);
  read(xt, yt);
  visit(xt, proj);
  int k;
  scanf("%d", &k);
  vector<chess> a(k);
  for (int i = 0; i < k; i++) {
    a[i] = read();
    visit(a[i].x, proj);
  }
  int adder = 0;
  for (int i = 1; i < proj.size(); i++) proj[i] += proj[i - 1];
  vector<int> ox;
  for (int i = 0; i < proj.size(); i++)
    if (proj[i] >= ox.size()) ox.push_back(i);
  xs = proj[xs];
  xt = proj[xt];
  for (auto &[t, x, y] : a) x = proj[x];
  int n = proj.back(), m = 8;
  vector<vector<int>> dis(n, vector<int>(m, -1));
  set<int> ur;
  for (auto [t, x, y] : a) setno(dis, x, y, -3);
  for (auto [t, x, y] : a) {
    if (t == 'N') {
      for (auto dx : {-1, 1})
        for (auto dy : {-1, 1}) {
          setno(dis, x + dx * 1, y + dy * 2, -2);
          setno(dis, x + dx * 2, y + dy * 1, -2);
        }
    }
    if (t == 'K') {
      for (auto dx : {-1, 0, 1})
        for (auto dy : {-1, 0, 1}) setno(dis, x + dx, y + dy, -2);
    }
    if (t == 'B' || t == 'Q') {
      for (auto dx : {-1, 1})
        for (auto dy : {-1, 1})
          for (int i = 1; setno(dis, x + dx * i, y + dy * i, -2); i++)
            ;
    }
    if (t == 'R' || t == 'Q') {
      for (auto [dx, dy] :
           vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}})
        for (int i = 1; setno(dis, x + dx * i, y + dy * i, -2); i++)
          ;
    }
  }
  printf("%d\n", bfs(dis, ox, xs, ys, xt, yt) + adder);
  return 0;
}