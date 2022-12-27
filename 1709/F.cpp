#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <vector>

inline int read() {
  register int ret, cc, sign = 1;
  while (!isdigit(cc = getchar())) {
    sign = cc == '-' ? -1 : sign;
  }
  ret = cc - 48;
  while (isdigit(cc = getchar())) ret = cc - 48 + ret * 10;
  return ret * sign;
}
inline void write(int x, char ch = '\n') {
  register int stk[20], tp;
  stk[tp = !x] = 0;
  while (x) stk[++tp] = x % 10, x /= 10;
  while (tp) putchar(stk[tp--] + '0');
  putchar(ch);
}

typedef std::vector<int> Poly;
const double PI = acos(-1.0);
inline int getrev(int);
inline int Qpow(int, int, int);
inline Poly Inverse(const Poly&);
inline void Read(Poly&);
inline void Print(const Poly&);
inline Poly operator*(const Poly&, const Poly&);
inline Poly operator-(const Poly&, const Poly&);
inline Poly operator+(const Poly&, const Poly&);
inline Poly operator/(const Poly&, const Poly&);
inline Poly operator%(const Poly&, const Poly&);

const int MAXN = 300010;
const int MOD = 998244353;
int g[MAXN];
int f[MAXN];
int N, K;
inline void mul_mod(int* a, int* b) {
  static int tmp[MAXN];
  for (int i = 0; i < K << 1; ++i) tmp[i] = 0;
  for (int i = 0; i < K; ++i)
    for (int j = 0; j < K; ++j)
      tmp[i + j] = (tmp[i + j] + 1ll * a[i] * b[j] % MOD) % MOD;
  for (int i = (K << 1) - 1; i >= K; --i)
    for (int j = 1; j <= K; ++j)
      tmp[i - j] = (tmp[i - j] + 1ll * tmp[i] * g[j] % MOD) % MOD;
  for (int i = 0; i < K; ++i) a[i] = tmp[i];
}
Poly Tg, Rg;
inline Poly mul_mod(const Poly& lhs, const Poly& rhs) {
  Poly A = lhs * rhs, B = A;
  int len = K - 1;
  std::reverse(A.begin(), A.end());
  A.resize(len);
  Poly C = A * Rg;
  C.resize(len);
  std::reverse(C.begin(), C.end());
  Poly D = B - Tg * C;
  D.resize(K);
  return D;
}
struct Complex {
  double x, y;
  Complex(double x = 0, double y = 0) : x(x), y(y) {}
  inline Complex operator+(const Complex& rhs) const {
    return Complex(x + rhs.x, y + rhs.y);
  }
  inline Complex operator-(const Complex& rhs) const {
    return Complex(x - rhs.x, y - rhs.y);
  }
  inline Complex operator*(const Complex& rhs) const {
    return Complex(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
  }
  inline Complex operator-() const { return Complex(-x, -y); }
  inline Complex operator!() const { return Complex(x, -y); }
  void print() { printf("(%f, %f)\n", x, y); }
};

Complex W[2][MAXN];
int rev[MAXN];
int Inv[MAXN];
inline int getrev(int n) {
  int bln = 1, bct = 0;
  while (bln <= n) bln <<= 1, bct++;
  for (int i = 0; i < bln; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bct - 1));
  for (int i = 0; i < bln; ++i) {
    W[0][i] = W[1][(bln - i) & (bln - 1)] =
        Complex(cos(2 * PI * i / bln), sin(2 * PI * i / bln));
  }
  return bln;
}
inline void getinv(int n) {
  Inv[1] = 1;
  for (int i = 2; i < n; ++i)
    Inv[i] = 1ll * (MOD - MOD / i) * Inv[MOD % i] % MOD;
}
inline void FFT(Complex* a, int n, int opt) {
  for (int i = 0; i < n; ++i)
    if (i < rev[i]) std::swap(a[i], a[rev[i]]);
  for (int i = 1, t = n >> 1; i < n; i <<= 1, t >>= 1) {
    for (int j = 0, p = (i << 1); j < n; j += p) {
      Complex* w = W[opt];
      for (int k = 0; k < i; ++k, w += t) {
        Complex x = a[j + k];
        Complex y = *w * a[j + k + i];
        a[j + k] = x + y;
        a[j + k + i] = x - y;
      }
    }
  }
  if (opt)
    for (int i = 0; i < n; ++i) a[i].x /= n, a[i].y /= n;
}
inline Poly MTT(const Poly& A, const Poly& B, int n) {
  static Complex a[MAXN], b[MAXN], c[MAXN], d[MAXN];
  for (size_t i = 0; i < A.size(); ++i)
    a[i] = Complex(A[i] & 32767, A[i] >> 15);
  for (int i = A.size(); i < n; ++i) a[i] = Complex();
  for (size_t i = 0; i < B.size(); ++i)
    b[i] = Complex(B[i] & 32767, B[i] >> 15);
  for (int i = B.size(); i < n; ++i) b[i] = Complex();
  FFT(a, n, 0), FFT(b, n, 0);
  for (int i = 0; i < n; ++i) {
    int j = (n - i) & (n - 1);
    c[i] = Complex(a[i].x + a[j].x, a[i].y - a[j].y) * 0.5 * b[i];
    d[i] = Complex(a[i].y + a[j].y, a[j].x - a[i].x) * 0.5 * b[i];
  }
  FFT(c, n, 1), FFT(d, n, 1);
  Poly C(n);
  for (int i = 0; i < n; ++i) {
    long long u = llround(c[i].x) % MOD, v = llround(c[i].y) % MOD;
    long long x = llround(d[i].x) % MOD, y = llround(d[i].y) % MOD;
    C[i] = (u + ((v + x) << 15) % MOD + (y << 30)) % MOD;
  }
  return C;
}
inline int Qpow(int a, int p = MOD - 2, int mod = MOD) {
  int ret = 1;
  p += (p < 0) * (mod - 1);
  while (p) {
    if (p & 1) ret = 1ll * ret * a % mod;
    a = 1ll * a * a % mod;
    p >>= 1;
  }
  return ret;
}
inline Poly operator*(const Poly& A, const Poly& B) {
  int len = A.size() + B.size() - 1;
  int bln = getrev(len);
  Poly C = MTT(A, B, bln);
  C.resize(len);
  return C;
}
inline Poly operator+(const Poly& lhs, const Poly& rhs) {
  Poly A(std::max(lhs.size(), rhs.size()));
  for (size_t i = 0; i < A.size(); ++i)
    A[i] =
        ((i < lhs.size() ? lhs[i] : 0) + (i < rhs.size() ? rhs[i] : 0)) % MOD;
  return A;
}
inline Poly operator-(const Poly& lhs, const Poly& rhs) {
  Poly A(std::max(lhs.size(), rhs.size()));
  for (size_t i = 0; i < A.size(); ++i)
    A[i] =
        ((i < lhs.size() ? lhs[i] : 0) - (i < rhs.size() ? rhs[i] : 0) + MOD) %
        MOD;
  return A;
}

inline Poly Inverse(const Poly& A) {
  Poly B(1, Qpow(A[0], MOD - 2));
  int n = A.size() << 1;
  for (int i = 2; i < n; i <<= 1) {
    Poly C(A);
    C.resize(i);
    B = Poly(1, 2) * B - C * B * B;
    B.resize(i);
  }
  B.resize(A.size());
  return B;
}
inline Poly operator/(const Poly& lhs, const Poly& rhs) {
  return lhs * Inverse(rhs);
}
inline Poly operator%(const Poly& lhs, const Poly& rhs) {
  Poly A(lhs), B(rhs);
  int len = A.size() - B.size() + 1;
  std::reverse(A.begin(), A.end());
  std::reverse(B.begin(), B.end());
  A.resize(len), B.resize(len);
  Poly C = A * Inverse(B);
  C.resize(len);
  std::reverse(C.begin(), C.end());
  Poly D = lhs - rhs * C;
  D.resize(rhs.size() - 1);
  return D;
}
inline void Read(Poly& A) { std::generate(A.begin(), A.end(), read); }
inline void Print(const Poly& A) {
  for (size_t i = 0; i < A.size(); ++i) printf("%d ", A[i]);
  puts("");
}
int a[MAXN];
int b[MAXN];
vector<int> comb(const vector<int>& arr, int k) {
  for (auto v : arr) cout << v << ' ';
  cout << endl;
  auto tmp = arr * arr;
  for (auto v : tmp) cout << v << ' ';
  cout << endl;
  cout << endl;
  vector<int> res(tmp.size() + 1);
  for (int i = 0; i < tmp.size(); i++)
    res[i] += 1ll * tmp[i] * (k - i + 1) % MOD;
  for (int i = 0; i < tmp.size(); i++)
    res[i + 1] += 1ll * tmp[i] * (k - i) % MOD;
  for (auto& v : res) v %= MOD;
  return res;
}
int main() {
  int n, k, f;
  scanf("%d%d%d", &n, &k, &f);
  vector<int> ans = {1, k};
  while (--n) ans = comb(ans, k);
  ans.resize(f + 1);
  printf("%d\n", 2 * ans[f] % MOD);
  return 0;
}