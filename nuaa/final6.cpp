#include <iostream>
#include <vector>
using namespace std;
#define int long long

const int mod = 998244353ll;
const int N = 200000;

vector<int> f(N), inv(N);

int pow(int x, int y) {
  int ret = 1;
  x = x % mod;
  while (y) {
    if (y & 1) ret = (ret * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return ret;
}

int C(int x, int y) { return (f[x] * inv[y] % mod) * inv[x - y] % mod; }

signed main() {
  f[0] = 1;
  for (int i = 1; i <= N; i++) {
    f[i] = (f[i - 1] * i) % mod;
  }
  inv[N] = pow(f[N], mod - 2);
  for (int i = N - 1; i >= 0; i--) {
    inv[i] = (inv[i + 1] * (i + 1)) % mod;
  }
  int n, m;
  cin >> n >> m;
  int ans = pow(m, n) % mod;
  for (int i = 1; i <= n; i++) {
    int tmp = (C(m + i - 1, m - 1) - m) % mod;
    tmp = (tmp * pow(m, n - i)) % mod;
    ans = (ans + tmp) % mod;
  }
  printf("%lld", ans);
}