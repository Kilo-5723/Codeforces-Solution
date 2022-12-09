#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 6000, maxm = 3000, alpha = 10;
char s[maxn][maxm];
struct node {
  node* ch[alpha];
  int q, v;
  node(int v = 0) : v(v) {}
};
void hmul(char s[], char t[], int k) {
  // auto a=s[0]*k;
  int sum = 0;
  for (int i = 0; i < maxm; i++) {
    sum += (int)s[i] * k;
    t[i] = sum % 10;
    sum /= 10;
  }
}
int mxm;
node* build(vector<int> a, int d) {
  // for (auto v : a) cout << v << ' ';
  // cout << endl;
  if (!a.size()) return NULL;
  if (a.size() == 1) {
    mxm = max(mxm, d);
    return new node(a[0]);
  }
  auto u = new node;
  int p = -1, val = a.size();
  for (int i = 0; i < maxm; i++) {
    vector<int> cnt(alpha);
    for (auto v : a) cnt[s[v][i]]++;
    int res = 0;
    for (int j = 0; j < alpha; j++) res = max(res, cnt[j]);
    if (res <= val) {
      val = res;
      p = i;
    }
  }
  if (d == 0) p = 50;
  u->q = p;
  // cout << val << endl;
  vector<int> arr[alpha];
  for (auto v : a) arr[s[v][p]].push_back(v);
  for (int i = 0; i < alpha; i++) u->ch[i] = build(arr[i], d + 1);
  return u;
}
void solve(node* u) {
  if (u->v) {
    cout << "! " << u->v << endl;
    string s;
    cin >> s;
    return;
  }
  cout << "? " << u->q << endl;
  int t;
  cin >> t;
  solve(u->ch[t]);
}
int main() {
  s[0][0] = 1;
  for (int i = 1; i < maxn; i++) hmul(s[i - 1], s[i], i);
  // for (int i = 1; i <= 10; i++) {
  //   for (int j = 0; j < 10; j++) putchar('0' + s[i][j]);
  //   puts("");
  // }
  vector<int> arr(maxn - 1);
  for (int i = 1; i < maxn; i++) arr[i - 1] = i;
  auto rt = build(arr, 0);
  int tt;
  // puts("1");
  // cout << mxm << endl;
  scanf("%d", &tt);
  while (tt--) solve(rt);
  return 0;
}