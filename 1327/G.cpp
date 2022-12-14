#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int alpha = 14, bit = 1 << alpha;
const int buff = 1e6;
vector<vector<int>> ch;
vector<int> fail;
vector<ll> val;
vector<vector<int>> go;
int newnode() {
  ch.push_back(vector<int>(alpha, 0));
  fail.push_back(0);
  val.push_back(0);
  go.push_back(vector<int>(alpha, 0));
  return ch.size() - 1;
}
void insert(char s[], int v, int u) {
  if (!*s) {
    val[u] += v;
    return;
  }
  int i = *s - 'a';
  if (!ch[u][i]) ch[u][i] = newnode();
  insert(s + 1, v, ch[u][i]);
}
void build() {
  queue<int> que;
  que.push(1);
  for (int i = 0; i < alpha; i++) go[1][i] = ch[1][i] ? ch[1][i] : 1;
  while (que.size()) {
    auto u = que.front();
    que.pop();
    for (int i = 0; i < alpha; i++)
      if (auto v = ch[u][i]) {
        auto w = fail[u];
        while (w && !ch[w][i]) w = fail[w];
        fail[v] = w ? ch[w][i] : 1;
        val[v] += val[fail[v]];
        for (int i = 0; i < alpha; i++)
          go[v][i] = ch[v][i] ? ch[v][i] : go[fail[v]][i];
        que.push(v);
      }
  }
}
char s[buff], t[buff];
pair<int, ll> run(int u, const char s[]) {
  ll res = 0;
  while (*s) {
    u = go[u][*s - 'a'];
    res += val[u];
    s++;
  }
  return {u, res};
}
int popcount(int n) { return n ? (n & 1) + popcount(n >> 1) : 0; }
int main() {
  int k;
  scanf("%d", &k);
  newnode();
  newnode();
  for (int i = 0; i < k; i++) {
    int t;
    scanf("%s%d", s, &t);
    insert(s, t, 1);
  }
  build();
  scanf("%s", s);
  int n = ch.size() - 1;
  vector<string> que;
  int cnt = 0;
  for (int i = 0; s[i]; i++) {
    int j = i;
    while (true) {
      t[j - i] = s[j];
      if (s[j] == '?') {
        t[j - i] = 0;
        cnt++;
        break;
      }
      if (!s[j]) break;
      j++;
    }
    que.push_back(t);
    i = j;
    if (s[i] == '?') que.push_back("?");
  }
  reverse(que.begin(), que.end());
  vector<vector<ll>> ans(n + 1, vector<ll>(1 << alpha, 0));
  for (auto s : que) {
    if (s == "?") {
      cnt--;
      vector<vector<ll>> dp(n + 1, vector<ll>(1 << alpha, -inf));
      for (int b = 0; b < bit; b++)
        if (popcount(b) == cnt)
          for (int i = 0; i < alpha; i++)
            if (!(b >> i & 1))
              for (int m = 1; m <= n; m++)
                dp[m][b] =
                    max(dp[m][b], ans[go[m][i]][b + (1 << i)] + val[go[m][i]]);
      swap(ans, dp);
    } else {
      vector<vector<ll>> dp(n + 1, vector<ll>(1 << alpha, 0));
      vector<int> selb;
      for (int b = 0; b < bit; b++)
        if (popcount(b) == cnt) selb.push_back(b);
      for (int m = 1; m <= n; m++) {
        auto [v, d] = run(m, s.c_str());
        for (auto b : selb) dp[m][b] = ans[v][b] + d;
      }
      swap(ans, dp);
    }
  }
  printf("%lld\n", ans[1][0]);
  return 0;
}