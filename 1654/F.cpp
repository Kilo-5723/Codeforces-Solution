#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 1 << 19;
char s[buff];
vector<int> radsort(const vector<int> &arr, const vector<int> &val) {
  int n = arr.size();
  vector<int> cnt(n + 100);
  for (auto v : val) cnt[v]++;
  for (int i = 1; i < n + 100; i++) cnt[i] += cnt[i - 1];
  vector<int> brr(n);
  for (int i = n - 1; i >= 0; i--) brr[--cnt[val[arr[i]]]] = arr[i];
  return brr;
}
vector<int> getrank(const vector<int> &arr, const vector<int> &val,
                    const vector<int> &las) {
  int n = arr.size();
  vector<int> rnk(n);
  for (int i = 0; i < n; i++) rnk[arr[i]] = i;
  for (int i = 1; i < n; i++)
    if (val[arr[i]] == val[arr[i - 1]] && las[arr[i]] == las[arr[i - 1]])
      rnk[arr[i]] = rnk[arr[i - 1]];
  return rnk;
}
vector<int> solve(char s[], int n) {
  vector<int> arr(n);
  for (int i = 0; i < n; i++) arr[i] = i;
  vector<int> rnk(n);
  for (int i = 0; i < n; i++) rnk[i] = s[n - i - 1] - 'a';
  arr = radsort(arr, rnk);
  vector<int> las(n);
  for (int k = 1; k < n; k <<= 1) {
    rnk = getrank(arr, rnk, las);
    las = rnk;
    for (int i = 0; i < n; i++)
      if (i & k) swap(rnk[i], rnk[i ^ k]);
    arr = radsort(arr, rnk);
  }
  return arr;
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int k = solve(s, 1 << n)[0];
  for (int i = 0; i < (1 << n); i++) putchar(s[i ^ k]);
  puts("");
  return 0;
}
