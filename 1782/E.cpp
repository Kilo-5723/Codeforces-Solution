#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct range {
  int id, l, r;
};
bool operator<(range a, range b) {
  if (a.l != b.l) return a.l < b.l;
  if (a.r != b.r) return a.r < b.r;
  return false;
}
void remove_cross(vector<range> &arr) {
  sort(arr.begin(), arr.end());
  vector<range> res;
  for (int i = 0; i < arr.size(); i++)
    if (!res.size() || res.back().r < arr[i].r) res.push_back(arr[i]);
  for (int i = 1; i < res.size(); i++)
    res[i - 1].r = min(res[i - 1].r, res[i].l - 1);
  swap(arr, res);
}
set<range> make_range(const vector<range> &arr) {
  int l = -1, r = -2;
  set<range> st;
  for (auto v : arr) {
    if (v.l == r + 1) {
      r = v.r;
    } else {
      st.insert({0, l, r});
      l = v.l;
      r = v.r;
    }
  }
  st.insert({0, l, r});
  st.erase({0, -1, -2});
  return st;
}
bool in_range(set<range> &st, range a) {
  auto it = st.lower_bound({0, a.l + 1, 0});
  if (it == st.begin()) return false;
  it--;
  return it->l <= a.l && it->r >= a.r;
}
void remove_cover(vector<range> &arr, set<range> &st) {
  vector<range> res;
  for (auto a : arr) {
    if (in_range(st, a)) continue;
    auto it = st.lower_bound({0, a.l + 1, 0});
    if (it != st.end()) a.r = min(a.r, it->l - 1);
    if (it != st.begin()) {
      it--;
      a.l = max(a.l, it->r + 1);
    }
    res.push_back(a);
  }
  swap(arr, res);
}
void write(vector<range> &up, vector<range> &down, vector<range> &mid) {
  // for (auto [id, l, r] : up)
  //   cout << "up " << id << ' ' << l << ' ' << r << endl;
  // for (auto [id, l, r] : down)
  //   cout << "down " << id << ' ' << l << ' ' << r << endl;
  // for (auto [id, l, r] : mid)
  //   cout << "mid " << id << ' ' << l << ' ' << r << endl;
  // cout << endl;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<range> up, down, mid;
    for (int i = 0; i < n; i++) {
      int u, l, d, r;
      scanf("%d%d%d%d", &u, &l, &d, &r);
      if (d == 1)
        up.push_back({i, l, r});
      else if (u == 2)
        down.push_back({i, l, r});
      else
        mid.push_back({i, l, r});
    }
    // puts("read");
    // write(up, down, mid);
    remove_cross(up);
    remove_cross(down);
    remove_cross(mid);
    // puts("remove cross");
    // write(up, down, mid);
    auto su = make_range(up), sd = make_range(down);
    // for (auto [id, l, r] : su) cout << "up range " << l << ' ' << r << endl;
    // for (auto [id, l, r] : sd) cout << "down range " << l << ' ' << r <<
    // endl;
    vector<range> tmp;
    swap(mid, tmp);
    for (auto a : tmp)
      if (in_range(su, a)) {
        if (in_range(sd, a))
          continue;
        else
          down.push_back(a);
      } else {
        if (in_range(sd, a))
          up.push_back(a);
        else
          mid.push_back(a);
      }
    // puts("modify mid");
    // write(up, down, mid);
    remove_cross(up);
    remove_cross(down);
    // puts("remove cross again");
    // write(up, down, mid);
    auto sm = make_range(mid);
    // for (auto [id, l, r] : sm) cout << "mid range " << l << ' ' << r << endl;
    // for (auto [id, l, r] : mid) cout << "mid " << l << ' ' << r << endl;
    remove_cover(up, sm);
    remove_cover(down, sm);
    // puts("remove cover");
    // write(up, down, mid);
    vector ans(n, vector<int>(4, 0));
    int sqr = 0;
    for (auto [id, l, r] : up) {
      ans[id][0] = 1;
      ans[id][1] = l;
      ans[id][2] = 1;
      ans[id][3] = r;
      sqr += r - l + 1;
    }
    for (auto [id, l, r] : down) {
      ans[id][0] = 2;
      ans[id][1] = l;
      ans[id][2] = 2;
      ans[id][3] = r;
      sqr += r - l + 1;
    }
    for (auto [id, l, r] : mid) {
      ans[id][0] = 1;
      ans[id][1] = l;
      ans[id][2] = 2;
      ans[id][3] = r;
      sqr += (r - l + 1) * 2;
    }
    printf("%d\n", sqr);
    for (auto &arr : ans)
      printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
  }
  return 0;
}