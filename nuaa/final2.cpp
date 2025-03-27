#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using vector2 = vector<vector<int>>;

struct T {
  int b, e, t;
};

int main() {
  int n, h;
  cin >> n >> h;
  vector<bool> vis(n + 1);
  vector<T> ro(h);
  int ans = 0;
  for (auto &[b, e, t] : ro) {
    cin >> b >> e >> t;
  }
  auto cmp = [](T a, T b) { return a.e < b.e; };
  sort(ro.begin(), ro.end(), cmp);
  for (auto [b, e, t] : ro) {
    auto count = [&]() {
      int cnt = 0;
      for (int i = e; i >= b; i--) {
        if (cnt >= t) return;
        if (vis[i]) cnt++;
      }
      for (int i = e; i >= b; i--) {
        if (cnt == t) return;
        if (!vis[i]) {
          // printf("%d %d %d\n", b, e, i);
          vis[i] = true;
          ans++;
          cnt++;
        }
      }
    };
    count();
  }
  cout << ans;
}
