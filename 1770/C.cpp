#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int lim = 6000;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
bool isprime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (!(n % i)) return false;
  return true;
}
bool check(const vector<ll> &a) {
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < i; j++)
      if (gcd(a[i], a[j]) != 1) return false;
  return true;
}
bool check(const vector<ll> &a, int n) {
  vector<bool> vis(n, false);
  for (int i = 0; i < a.size(); i++)
    for (int j = i + 1; j < a.size(); j++)
      if (!((a[j] - a[i]) % n)) vis[a[i] % n] = true;
  for (auto v : vis)
    if (!v) return true;
  return false;
}
int main() {
  int tt;
  scanf("%d", &tt);
  vector<int> prime;
  for (int i = 2; i <= lim; i++)
    if (isprime(i)) prime.push_back(i);
  // for (auto v : prime) cout << v << endl;
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    if (a.size() < n) {
      puts("NO");
      continue;
    }
    bool flg = true;
    for (auto p : prime) flg = flg && check(a, p);
    puts(flg ? "YES" : "NO");
  }
  return 0;
}