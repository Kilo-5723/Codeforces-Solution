#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct sofa {
  int x1, y1, x2, y2;
};
bool check(sofa a, const vector<int>& cx1, const vector<int>& cy1,
           const vector<int>& cx2, const vector<int>& cy2, int cl, int cr,
           int ct, int cb) {
  // cout << a.x1 << ' ' << a.x2 << ' ' << a.y1 << ' ' << a.y2 << endl;
  // cout << cx1[a.x2 - 1] << ' ' << cx2[a.x1 + 1] << ' ' << cy1[a.y2 - 1] << ' '
  //      << cy2[a.y1 + 1] << endl;
  if (cx1[a.x2 - 1] - (a.x1 < a.x2) != cl) return false;
  if (cx2[a.x1 + 1] - (a.x1 < a.x2) != cr) return false;
  if (cy1[a.y2 - 1] - (a.y1 < a.y2) != ct) return false;
  if (cy2[a.y1 + 1] - (a.y1 < a.y2) != cb) return false;
  return true;
}
int main() {
  int d;
  scanf("%d", &d);
  int n, m;
  scanf("%d%d", &n, &m);
  vector<sofa> a(d);
  vector<int> cx1(n + 2), cy1(m + 2), cx2(n + 2), cy2(m + 2);
  for (int i = 0; i < d; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    cx1[x1]++;
    cx2[x2]++;
    cy1[y1]++;
    cy2[y2]++;
    a[i] = {x1, y1, x2, y2};
  }
  for (int i = 0; i <= n; i++) cx1[i + 1] += cx1[i];
  for (int i = 0; i <= m; i++) cy1[i + 1] += cy1[i];
  for (int i = n + 1; i; i--) cx2[i - 1] += cx2[i];
  for (int i = m + 1; i; i--) cy2[i - 1] += cy2[i];
  int cl, cr, ct, cb;
  scanf("%d%d%d%d", &cl, &cr, &ct, &cb);
  for (int i = 0; i < d; i++)
    if (check(a[i], cx1, cy1, cx2, cy2, cl, cr, ct, cb)) {
      printf("%d\n", i + 1);
      return 0;
    }
  puts("-1");
  // cout << lx1 << ' ' << rx1 << endl;
  // cout << lx2 << ' ' << rx2 << endl;
  // cout << ly1 << ' ' << ry1 << endl;
  // cout << ly2 << ' ' << ry2 << endl;
  return 0;
}