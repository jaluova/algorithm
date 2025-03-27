#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using vector2 = vector<vector<int>>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> can(n + 1);
  vector2 map = vector2(n + 1);
  for (int i = 1; i <= n; i++) cin >> can[i];
  while (m--) {
    int u, v;
    cin >> u >> v;
    map[u].push_back(v);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (can[i] == can[j]) continue;
      auto build = [&]() {
        queue<int> q;
        vector<bool> vis(n + 1);
        vector<bool> have(6);
        q.push(i);
        q.push(j);
        while (!q.empty()) {
          int v = q.front();
          q.pop();
          if (vis[v]) continue;
          vis[v] = true;
          if (have[can[v]]) return false;
          have[can[v]] = true;
          for (int u : map[v]) {
            q.push(u);
          }
        }
        return true;
      };
      if (build()) ans++;
    }
  }
  cout << ans;
}
