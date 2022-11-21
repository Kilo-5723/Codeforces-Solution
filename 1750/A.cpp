#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int fir;
    scanf("%d", &fir);
    bool flg = true;
    while (--n) {
      int t;
      scanf("%d", &t);
      if (t < fir) flg = false;
    }
    puts(flg ? "Yes" : "No");
  }
  return 0;
}