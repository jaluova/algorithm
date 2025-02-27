#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(n), r(n);

  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }

  sort(l.begin(), l.end());
  sort(r.begin(), r.end());

  int ans = 0;

  for (int i = 0; i < n; i++) {
    ans += r[i] - l[i];
    if (i) ans -= max(r[i - 1] - l[i], 0);
  }

  cout << ans << '\n';

  return 0;
}