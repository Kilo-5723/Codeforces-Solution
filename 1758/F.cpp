#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<pair<int, int>> opr_add, opr_del;
void init() {
  opr_add.clear();
  opr_del.clear();
}
void flush() {
  printf("%lu\n", opr_add.size());
  for (auto [l, r] : opr_add) printf("%d %d\n", l + 1, r);
  printf("%lu\n", opr_del.size());
  for (auto [l, r] : opr_del) printf("%d %d\n", l + 1, r);
}
struct value {
  int l, r, sum;
};
struct SegTree {
  struct node{
    struct value
  }
} void add(int x) {
  one.insert(x);
  zero.erase(x);
  pair<int, int> tmp;
  if (auto ptr = get_include(x)) {
    tmp = *ptr;
    range.erase(tmp);
    opr_del.push_back(tmp);
    zero.insert(tmp.second + 1);
    zero.insert(tmp.second);
    przero.insert(tmp.second);
    tmp.second += 2;
  } else {
    tmp = {(x | 1) - 1, (x | 1) + 1};
    zero.insert(x ^ 1);
  }
  while (auto ptr = get_include(tmp.second)) {
    range.erase(*ptr);
    opr_del.push_back(*ptr);
    tmp.second = ptr->second;
  }
  range.insert(tmp);
  opr_add.push_back(tmp);
}
void del(int x) {
  one.erase(x);
  zero.insert(x);
  auto pr = *get_include(x);
  range.erase(tmp);
  opr_del.push_back(tmp);
  if () }
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    x--;
    init();
    if (one.count(x)) {
      if (one.count(x ^ 1)) {
        auto it = range.lower_bound({x, -1});
        if (it == range.begin()) {
        }
      } else {
      }
    } else {
      if (one.count(x ^ 1)) {
      }
      del(x);
    }
    flush();
  }
  return 0;
}