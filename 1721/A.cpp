#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    char a[5];
    scanf("%s", a);
    scanf("%s", a + 2);
    set<char> st;
    for (int i = 0; i < 4; i++) st.insert(a[i]);
    printf("%lu\n", st.size() - 1);
  }
  return 0;
}