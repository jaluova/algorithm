// 蓝桥杯 棋盘
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    auto maze = vector(n + 1, vector<int>(n + 1, 0));

    // for (int i = n - 1; i >= 0; i--) {
    //     for (int j = n - 1; j >= 0; j--) {
    //         if (i) maze[i][j] ^= maze[i - 1][j];
    //     }
    //     adjacent_difference(maze[i].begin(), maze[i].end(), maze[i].begin(),
    //                         [](int prev, int cur) { return prev ^ cur; });
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << maze[i][j];
    //     cout << endl;
    // }

    // 或者计算正负
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        maze[x1][y1] ^= 1;
        maze[x1][y2 + 1] ^= 1;
        maze[x2 + 1][y1] ^= 1;
        maze[x2 + 1][y2 + 1] ^= 1;
    }

    for (int i = 0; i < n; i++) {
        partial_sum(maze[i].begin(), maze[i].end(), maze[i].begin(),
                    [](int prev, int cur) { return prev ^ cur; });
        for (int j = 0; j < n; j++) {
            if (i) maze[i][j] ^= maze[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << maze[i][j];
        cout << endl;
    }

    return 0;
}