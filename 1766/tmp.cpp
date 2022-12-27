// 这回只花了114514min就打完了。
// 真好。记得多手造几组。ACM拍什么拍。
#include "bits/stdc++.h"
using namespace std;
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) {
  return cin >> a.first >> a.second;
}
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a) {
  for (auto &x : a) cin >> x;
  return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) {
  return cout << a.first << ' ' << a.second;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a) {
  for (auto &x : a) cout << x << '\n';
  return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a) {
  int n = a.size();
  if (!n) return cout;
  cout << a[0];
  for (int i = 1; i < n; i++) cout << ' ' << a[i];
  return cout;
}
template <typename typC, typename typD>
bool cmin(typC &x, const typD &y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <typename typC, typename typD>
bool cmax(typC &x, const typD &y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
template <typename typC>
vector<typC> range(typC l, typC r, typC step = 1) {
  assert(step > 0);
  int n = (r - l + step - 1) / step, i;
  vector<typC> res(n);
  for (i = 0; i < n; i++) res[i] = l + step * i;
  return res;
}
#if !defined(ONLINE_JUDGE) && defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
// template<typename T1,typename T2> void inc(T1 &x,const T2 &y) { if
// ((x+=y)>=p) x-=p; } template<typename T1,typename T2> void dec(T1 &x,const T2
// &y) { if ((x+=p-y)>=p) x-=p; }
namespace net {
const int N = 4e5 + 50;  // number of points
namespace flow {
typedef ll wT;                             // single flow
typedef ll cT;                             // total flow
const cT inf = numeric_limits<cT>::max();  // maximum
struct Q {
  int v;
  wT w;
  int id;
};
vector<Q> e[N];
int fc[N], q[N];
int n, s, t;
}  // namespace flow
using flow::fc;
namespace match {
int lk[N];
bool ed[N];
int kl[N];
vector<int> e[N];
namespace cost_flow {
typedef ll wT;
typedef ll cT;
const cT inf = numeric_limits<cT>::max();
struct Q {
  int v;
  wT w;
  cT c;
  int id;
};
vector<Q> e[N];
cT dis[N];
int pre[N], pid[N], ipd[N];
bool ed[N];
int n, s, t;
pair<wT, cT> spfa() {
  queue<int> q;
  fill_n(dis, n, inf);
  memset(ed, 0, n * sizeof ed[0]);
  q.push(s);
  dis[s] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    ed[u] = 0;
    for (auto [v, w, c, id] : e[u])
      if (w && dis[v] > dis[u] + c) {
        dis[v] = dis[u] + c;
        pre[v] = u;
        pid[v] = e[v][id].id;
        ipd[v] = id;
        if (!ed[v]) q.push(v), ed[v] = 1;
      }
  }
  if (dis[t] >= 0) return {0, 0};
  wT mw = numeric_limits<wT>::max();
  for (int i = t; i != s; i = pre[i]) mw = min(mw, e[pre[i]][pid[i]].w);
  for (int i = t; i != s; i = pre[i])
    e[pre[i]][pid[i]].w -= mw, e[i][ipd[i]].w += mw;
  return {mw, (cT)mw * dis[t]};
}
pair<wT, cT> mcmf_spfa(const vector<tuple<int, int, wT, cT>> &edges, int S,
                       int T)  //[0,n]
{
  s = S;
  t = T;
  n = max(s, t);
  for (auto [u, v, w, c] : edges) n = max({n, u, v});
  ++n;
  assert(n < N);
  for (int i = 0; i < n; i++) e[i].clear();
  for (auto [u, v, w, c] : edges)
    if (u != v) {
      e[u].push_back({v, w, c, (int)e[v].size()});
      e[v].push_back({u, 0, -c, (int)e[u].size() - 1});
    }
  pair<wT, cT> r{0, 0}, rr;
  while ((rr = spfa()).first && rr.second < 0)
    r = {r.first + rr.first, r.second + rr.second};
  return r;
}
}  // namespace cost_flow
}  // namespace match
}  // namespace net
using net::flow::e;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(15);
  int n, m, i;
  cin >> n >> m;
  vector<tuple<int, int, ll, ll>> edges(m);
  vector<ll> ans(m);
  vector<int> rd(n + 1);
  i = 0;
  for (auto &[u, v, w, c] : edges)
    cin >> u >> v >> w >> c, rd[u] += w & 1, rd[v] -= w & 1, ans[i++] = w & 1,
                                                             w >>= 1;
  ll tot = 0;
  for (i = 2; i < n; i++) {
    if (rd[i] % 2) {
      cout << "Impossible\n";
      return 0;
    }
    rd[i] /= 2;
    if (rd[i] > 0) {
      edges.push_back({i, n, rd[i], -1'000'000'000});
      tot -= rd[i] * 1'000'000'000ll;
    } else if (rd[i] < 0) {
      // dbg(1,rd[i]);
      edges.push_back({1, i, -rd[i], -1'000'000'000});
      tot -= (-rd[i]) * 1'000'000'000ll;
    }
  }
  auto [W, C] = net::match::cost_flow::mcmf_spfa(edges, 1, n);
  // dbg(W,C);
  if (C > tot + 500'000'000) {
    cout << "Impossible\n";
    return 0;
  }
  for (i = 1; i <= n; i++) reverse(all(e[i]));
  for (i = 0; i < m; i++) {
    auto [u, v, w, c] = edges[i];
    // while (e[u].size()&&e[u].back().v>n) e[u].pop_back();
    // while (e[v].size()&&e[v].back().v>n) e[v].pop_back();
    ans[i] += 2 * e[v].back().w;
    e[u].pop_back();
    e[v].pop_back();
  }
  cout << "Possible\n" << ans << endl;
}