#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char f[105][105];
bool vis[105][105];
int n, m;
void dfs(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = true;
  if (x == n && y == m) {
    cout << "Yes\n";
    exit(0);
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (!vis[nx][ny] && nx > 0 && nx <= n && ny > 0 && ny <= m &&
        f[nx][ny] != '#') {
      dfs(nx, ny);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> f[i][j];
    }
  }
  dfs(1, 1);
  cout << "No\n";
  return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> dx = {1, 0, -1, 0};
// vector<int> dy = {0, 1, 0, -1};

// vector<string> map(105);
// bool vis[105][105];

// int n, m;

// void dfs(int x, int y) {
//   if (x < 0 || x >= n) return;
//   if (y < 0 || y >= m) return;
//   if (map[x][y] == '#') return;
//   if (!vis[x][y])
//     vis[x][y] = true;
//   else
//     return;
//   if (x == n - 1 && y == m - 1) {
//     cout << "Yes\n";
//     exit(0);
//   }
//   for (int i = 0; i < 4; i++) {
//     int nx = x + dx[i];
//     int ny = y + dy[i];
//     dfs(nx, ny);
//   }
// };

// int main() {
//   cin >> n >> m;

//   for (auto& s : map) {
//     cin >> s;
//   }

//   dfs(0, 0);

//   cout << "No\n";

//   return 0;
// }