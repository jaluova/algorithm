#include <iostream>
#include <vector>
#define int long long
using namespace std;

constexpr int mod = 1e9 + 7;
using matrix = vector<vector<int>>;

matrix multi(const matrix& A, const matrix& B) {
  int n = A.size();
  int m = B[0].size();
  int p = B.size();
  matrix C(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < p; k++) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
      }
    }
  }
  return C;
}

matrix pow(matrix& A, int k) {
  int n = A.size();
  matrix ret(n, vector<int>(n));
  for (int i = 0; i < n; i++) ret[i][i] = 1;

  while (k) {
    if (k & 1) ret = multi(ret, A);
    A = multi(A, A);
    k >>= 1;
  }
  return ret;
}

int f(int n) {
  matrix F = {{1, 1}, {1, 0}};
  matrix ans = pow(F, n - 1);
  return ans[0][0];
}

int gcd(int x, int y) {
  while (y) {
    int tmp = x % y;
    x = y;
    y = tmp;
  }
  return x;
}

signed main() {
  int x, y;
  cin >> x >> y;
  int n = gcd(x + 1, y + 1);
  cout << f(n);
}