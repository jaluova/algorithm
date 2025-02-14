#include <limits.h>

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    auto maze = vector(n, vector<int>(m));
    for (auto& row : maze)
        for (auto& x : row) cin >> x;

    auto sum = vector(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        partial_sum(maze[i - 1].begin(), maze[i - 1].end(), sum[i].begin() + 1);
        for (int j = 1; j <= m; j++) {
            sum[i][j] += sum[i - 1][j];
        }
    }

    int max = INT_MIN;

    int x, y;

    for (int i = 0; i <= n - c; i++) {
        for (int j = 0; j <= n - c; j++) {
            int v =
                sum[i + c][j + c] - sum[i + c][j] - sum[i][j + c] + sum[i][j];
            if (v > max) {
                max = v;
                x = i + 1;
                y = j + 1;
            }
        }
    }

    cout << x << " " << y << endl;

    return 0;
}

// int N, M, C;
// cin >> N >> M >> C;

// vector<vector<int>> a(N + 2, vector<int>(M + 2, 0));
// vector<vector<int>> sum(N + 2, vector<int>(M + 2, 0));

// for (int i = 1; i <= N; i++)
//     for (int j = 1; j <= M; j++) cin >> a[i][j];

// for (int i = 1; i <= N + 1; i++)
//     for (int j = 1; j <= M + 1; j++) {
//         sum[i][j] =
//             sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
//     }

// int X, Y, max = INT_MIN;

// C--;
// for (int i = 1; i <= N - C; i++) {
//     for (int j = 1; j <= M - C; j++) {
//         int cnt = sum[i + C][j + C] - sum[i - 1][j + C] -
//                     sum[i + C][j - 1] + sum[i - 1][j - 1];

//         if (cnt > max) {
//             max = cnt;
//             X = i;
//             Y = j;
//         }
//     }
// }

// cout << X << " " << Y << endl;
