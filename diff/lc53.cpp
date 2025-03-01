#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), m(n);
  for (auto &x : a) cin >> x;

  for (int i = n - 1; i >= 0; i--) {
    m[i] = a[i];
    if (i != n - 1) m[i] = max(a[i], m[i + 1] + a[i]);
  }

  int ans = INT_MIN;
  for (auto x : m) ans = max(ans, x);
  cout << ans << endl;

  return 0;
}

// int n;
// cin >> n;
// vector<int> a(n), sum(n + 1);
// for (auto &x : a) cin >> x;

// partial_sum(a.begin(), a.end(), sum.begin() + 1);

// int ans = INT_MIN;

// for (int i = 0; i < n; i++) {
//   int m = *max_element(sum.begin() + i + 1, sum.end());
//   ans = max(ans, m - sum[i]);
// }
// cout << ans << endl;
