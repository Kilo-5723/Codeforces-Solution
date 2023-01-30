// #pragma once

#include <cmath>
#include <complex>
#include <vector>

namespace polynomial {

typedef std::complex<double> cplx;

const double pi = std::acos((double)-1.0);
const int len = 15, mask = (1 << len) - 1;

struct UnitRoot {
  static std::vector<cplx> w;
  static std::vector<cplx> get_root(int n) {
    n = 1 << 32 - __builtin_clz(n);
    if (n > w.size()) {
      w.resize(n);
      for (int i = 0; i < n; i++)
        w[i] = cplx(std::cos(2 * i * pi / n), std::sin(2 * i * pi / n));
    }
    int m = w.size() / n;
    std::vector<cplx> res(n);
    for (int i = 0, j = 0; i < n; i++, j += m) res[i] = w[j];
    return res;
  }
};
std::vector<cplx> UnitRoot::w;

void fft(std::vector<cplx> &p, const std::vector<cplx> &w) {
  int n = w.size();
  for (int i = 1, j = 0; i < n - 1; ++i) {
    int s = n;
    do {
      s >>= 1;
      j ^= s;
    } while (~j & s);
    if (i < j) {
      swap(p[i], p[j]);
    }
  }
  for (int d = 0; (1 << d) < n; ++d) {
    int m = 1 << d, m2 = m * 2, rm = n >> (d + 1);
    for (int i = 0; i < n; i += m2) {
      for (int j = 0; j < m; ++j) {
        auto &p1 = p[i + j + m], &p2 = p[i + j];
        auto t = w[rm * j] * p1;
        p1 = p2 - t;
        p2 = p2 + t;
      }
    }
  }
}

std::vector<long long> convolution(const std::vector<long long> &a,
                                   const std::vector<long long> &b) {
  std::vector<cplx> w = UnitRoot::get_root(a.size() + b.size() - 1);
  int n = w.size();
  std::vector<cplx> A(n), B(n), C(n), D(n);
  for (int i = 0; i < a.size(); ++i) A[i] = cplx(a[i] >> len, a[i] & mask);
  for (int i = 0; i < b.size(); ++i) B[i] = cplx(b[i] >> len, b[i] & mask);
  fft(A, w), fft(B, w);
  for (int i = 0; i < n; ++i) {
    int j = (n - i) % n;
    cplx da = (A[i] - conj(A[j])) * cplx(0, -0.5),
         db = (A[i] + conj(A[j])) * cplx(0.5, 0),
         dc = (B[i] - conj(B[j])) * cplx(0, -0.5),
         dd = (B[i] + conj(B[j])) * cplx(0.5, 0);
    C[j] = da * dd + da * dc * cplx(0, 1);
    D[j] = db * dd + db * dc * cplx(0, 1);
  }
  fft(C, w), fft(D, w);
  std::vector<long long> res(a.size() + b.size() - 1);
  for (int i = 0; i < res.size(); ++i) {
    long long da = (long long)(C[i].imag() / n + 0.5),
              db = (long long)(C[i].real() / n + 0.5),
              dc = (long long)(D[i].imag() / n + 0.5),
              dd = (long long)(D[i].real() / n + 0.5);
    res[i] = ((dd << (len * 2)) + ((db + dc) << len) + da);
  }
  return res;
}

}  // namespace polynomial
using namespace std;
typedef long long ll;
vector<ll> qpow(vector<ll> a, ll b) {
  vector<ll> res{1};
  while (b) {
    if (b & 1) res = polynomial::convolution(res, a);
    a = polynomial::convolution(a, a);
    for (auto &v : res) v = (bool)v;
    for (auto &v : a) v = (bool)v;
    b >>= 1;
  }
  return res;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<ll> a(1001);
  while (n--) {
    int t;
    scanf("%d", &t);
    a[t]++;
  }
  auto res = qpow(a, k);
  for (int i = 0; i < res.size(); i++)
    if (res[i]) printf("%d ", i);
  puts("");
  return 0;
}