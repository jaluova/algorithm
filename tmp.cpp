#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  long long offset = INT_MAX + 1;
  int n;
  cin >> n;
  vector<int> d(offset * 2);
  while (n--) {
    int l, r;
    cin >> l >> r;
    l += offset;
    r += offset;
    d[l] += 1;
    d[r] -= 1;
  }

  partial_sum(d.begin(), d.end(), d.begin());

  int ans = 0;

  for (auto &x : d)
    if (x > 0) ans++;

  cout << ans << endl;

  return 0;
}