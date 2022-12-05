#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int digit = 31;
struct node {
  node *ch[2];
  int siz;
};
node *root;
void insert(node *&u, int n, int k) {
  if (!u) u = new node{{NULL, NULL}, 0};
  u->siz++;
  if (k == -1) return;
  insert(u->ch[n >> k & 1], n, k - 1);
}
int getsiz(node *u) { return u ? u->siz : 0; }
int query(node *u, int x, int y, int k) {
  if (!u) return 0;
  if (k == -1) return getsiz(u);
  bool a = x >> k & 1, b = y >> k & 1;
  return b ? query(u->ch[a ^ 1], x, y, k - 1)
           : getsiz(u->ch[a ^ 1]) + query(u->ch[a], x, y, k - 1);
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int s = 0;
  ll ans = 0;
  root = NULL;
  for (int i = 0; i < n; i++) {
    insert(root, s, digit);
    int t;
    scanf("%d", &t);
    s ^= t;
    ans += query(root, s, k, digit);
    // printf("%lld\n", ans);
  }
  printf("%lld\n", ans);
  return 0;
}