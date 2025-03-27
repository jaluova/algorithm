#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  adjacent_difference(a.begin(), a.end(), a.begin());
  ll pos = 0, neg = 0;
  for (auto x : a) {
    if (x > 0)
      pos += x;
    else
      neg += x;
  }
  cout << max(pos, abs(neg)) << endl;
}