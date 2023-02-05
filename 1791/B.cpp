#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<char> s(n + 1);
    scanf("%s", s.data());
    s.pop_back();
    int x = 0, y = 0;
    bool flg = false;
    for (auto ch : s) {
      switch (ch) {
        case 'R':
          x++;
          break;
        case 'U':
          y++;
          break;
        case 'L':
          x--;
          break;
        case 'D':
          y--;
          break;
      }
      flg = flg || x == 1 && y == 1;
    }
    puts(flg ? "YES" : "NO");
  }
  return 0;
}