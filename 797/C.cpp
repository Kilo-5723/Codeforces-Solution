#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 2e5, alpha = 26;
char s[buff];
bool check(char ch, const vector<int>& cnt) {
  for (int i = 0; i < ch - 'a'; i++)
    if (cnt[i]) return false;
  return true;
}
int main() {
  scanf("%s", s);
  vector<char> a;
  vector<int> cnt(alpha);
  for (int i = 0; s[i]; i++) cnt[s[i] - 'a']++;
  for (int i = 0; s[i]; i++) {
    a.push_back(s[i]);
    cnt[a.back() - 'a']--;
    while (a.size() && check(a.back(), cnt)) {
      putchar(a.back());
      a.pop_back();
    }
  }
  reverse(a.begin(), a.end());
  for (auto ch : a) putchar(ch);
  puts("");
  return 0;
}