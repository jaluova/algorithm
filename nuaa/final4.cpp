#include <iostream>
#include <vector>

using namespace std;

using vector2 = vector<vector<int>>;

void solve() {
  int n, m;
  cin >> n >> m;
  vector2 a = vector2(n, vector<int>(m));
  for (auto& row : a)
    for (auto& x : row) cin >> x;
  while (1) {
    if (a.empty()) break;
    if (a.size() == 1 || a[0].size() == 1) break;
    vector2 b;
    for (size_t i = 0; i < a.size(); i++) {
      vector<int> tmp;
      bool flag = false;
      for (size_t j = 0; j < a[0].size(); j++) {
        if (a[i][j] != a[i][0]) {
          flag = true;
        }
        tmp.push_back(a[i][j]);
      }
      if (flag) b.push_back(tmp);
    }
    if (b.empty()) break;
    if (b.size() == 1 || b[0].size() == 1) break;
    vector2 c(b.size());
    for (size_t j = 0; j < b[0].size(); j++) {
      vector<int> tmp;
      bool flag = false;
      for (size_t i = 0; i < b.size(); i++) {
        if (b[i][j] != b[0][j]) {
          flag = true;
        }
        tmp.push_back(b[i][j]);
      }
      if (flag) {
        for (size_t i = 0; i < b.size(); i++) {
          c[i].push_back(tmp[i]);
        }
      }
    }
    if (a == c) {
      cout << "No\n";
      return;
    }
    a = c;
  }
  cout << "Yes\n";
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
