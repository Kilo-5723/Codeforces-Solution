#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int fir = 0;
    bool flg=false;
    n--;
    scanf("%d", &fir);
    while (n--) {
      int t;
      scanf("%d", &t);
      if (t<fir) flg=true;
    }
    puts(flg?"Alice":"Bob");
  }
  return 0;
}