#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int buff = 100;
char s[buff];
int main() {
  int n;
  ll p;
  scanf("%d%lld", &n, &p);
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    arr[i] = strlen(s);
  }
  reverse(arr.begin(), arr.end());
  ll cnt = 0, cur = 0;
  for (auto v : arr) {
    cur = cur * 2 + (v == 8);
    cnt += cur;
  }
  printf("%lld\n", cnt * p / 2);
  return 0;
}