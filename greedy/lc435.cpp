#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using v1 = vector<int>;
using v2 = vector<vector<int>>;
using ll = long long;

int main() {
  v2 intervals = {{1, 2}, {2, 3}};
  sort(intervals.begin(), intervals.end(),
       [](auto& a, auto& b) { return a[1] < b[1]; });
  ll cnt = 0;
  int r = -1ll << 31;
  for (auto x : intervals) {
    if (x[0] >= r)
      r = x[1];
    else
      cnt++;
  }
  cout << cnt << endl;
}