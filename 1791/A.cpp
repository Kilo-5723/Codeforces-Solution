#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  string str = "codeforces";
  while (tt--) {
    vector<char> s(2);
    scanf("%s", s.data());
    bool flg = false;
    for (auto ch : str) flg = flg || ch == s[0];
    puts(flg ? "YES" : "NO");
  }
  return 0;
}