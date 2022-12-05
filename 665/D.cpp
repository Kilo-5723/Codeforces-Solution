#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> isprime;
int main() {
  isprime.assign(3e6, true);
  for (int i = 2; i < isprime.size(); i++)
    if (isprime[i]) {
      for (int j = i * 2; j < isprime.size(); j += i) isprime[j] = false;
    }
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<int> ans = {a[0]};
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (isprime[a[i] + a[j]]) ans = {a[i], a[j]};
  int cnt = 0;
  vector<int> res = {};
  for (int i = 0; i < n; i++) cnt += a[i] == 1;
  for (int i = 0; i < n; i++)
    if (a[i] != 1)
      if (isprime[a[i] + 1]) res = {a[i]};
  for (int i = 0; i < n; i++)
    if (a[i] != 1)
      for (int j = i + 1; j < n; j++)
        if (a[j] != 1)
          if (isprime[a[i] + a[j]] && isprime[a[i] + 1] && isprime[a[j] + 1])
            res = {a[i], a[j]};
  if (cnt + res.size() > ans.size()) {
    ans.assign(cnt, 1);
    ans.insert(ans.end(), res.begin(), res.end());
  }
  printf("%lu\n", ans.size());
  for (auto v : ans) printf("%d ", v);
  puts("");
  return 0;
}