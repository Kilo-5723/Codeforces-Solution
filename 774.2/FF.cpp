#include <cassert>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int inf = 1e9;
const int maxn = 105;
void match(int gra[][maxn], int n, int res[]) {
  // static int deg[maxn * 2];
  // fill(deg, deg + n * 2, 0);
  // for (int i = 0; i < n; i++)
  //   for (int j = 0; j < n; j++) {
  //     deg[i] += gra[i][j];
  //     deg[j + n] += gra[i][j];
  //   }
  for (int t = 0; t < n; t++) {
    int u = 0, v = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (gra[i][j] > gra[u][v]) {
          u = i;
          v = j;
          // w = deg[i] + deg[j + n];
        }
    // assert(w < inf);
    // printf("u, v, w: %d, %d, %d; %d %d\n", u, v, w, deg[u], deg[v]);
    // deg[u] = inf;
    // deg[v + n] = inf;
    for (int i = 0; i < n; i++) gra[u][i] = gra[i][v] = 0;
    res[u] = v;
  }
}
void minor(int arr[], int pos, int n, int *res, int &sizr) {
  // sizr = 0;
  while (~arr[pos]) {
    int val = arr[pos], stp = (val + n - pos) % n;
    arr[pos] = -1;
    while (stp--) res[sizr++] = val;
    pos = val;
  }
}
void major(int arr[], int pos, int n, int res[]) {
  static int lis[maxn];
  int sizl = 0, sizr = 0;
  while (~arr[pos]) {
    int val = arr[pos];
    lis[sizl++] = pos;
    arr[pos] = -1;
    pos = val;
  }
  for (int i = 1; i < sizl; i++) {
    while (pos != lis[i]) {
      if (~arr[pos]) minor(arr, pos, n, res, sizr);
      res[sizr++] = lis[i];
      pos = (pos + 1) % n;
    }
  }
  do {
    if (~arr[pos]) minor(arr, pos, n, res, sizr);
    res[sizr++] = lis[0];
    pos = (pos + 1) % n;
  } while (pos != lis[0]);
  while (sizr < n * (n - 1)) res[sizr++] = pos;
}
int main() {
  int n;
  scanf("%d", &n);
  static int a[maxn][maxn];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]--;
    }
  static int gra[maxn][maxn];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fill(gra[j], gra[j] + n, 0);
      for (int k = i; k < n; k++) gra[j][a[j][k]]++;
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) printf("%d ", gra[i][j]);
    //   puts("");
    // }
    // puts("");
    static int res[maxn];
    match(gra, n, res);
    // for (int i = 0; i < n; i++) printf("%d ", res[i] + 1);
    // puts("");
    for (int j = 0; j < n; j++)
      for (int k = i; k < n; k++)
        if (a[j][k] == res[j]) {
          swap(a[j][k], a[j][i]);
          break;
        }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) printf("%d ", a[i][j] + 1);
    //   puts("");
    // }
    // puts("");
  }
  // if (n == 100) return 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) swap(a[i][j], a[j][i]);
  static int ans[maxn * maxn][maxn];
  for (int i = 0; i < n; i++) {
    static int res[maxn * maxn];
    major(a[i], i, n, res);
    for (int j = 0; j < n * (n - 1); j++) {
      ans[j][(j + i) % n] = res[j];
    }  // printf("%d ",res[j]);} puts("");
  }
  printf("%d\n", n * (n - 1));
  for (int i = 0; i < n * (n - 1); i++)
    for (int j = 0; j < n; j++)
      printf("%d%c", ans[i][j] + 1, j < n - 1 ? ' ' : '\n');

  return 0;
}