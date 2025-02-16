// 高效清理
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N = 3010;
    const int offset = 1005;

    int n, m, k;
    cin >> n >> m >> k;
    auto origin = vector(n, vector(m, 0ll));
    for (auto &row : origin)
        for (auto &x : row) cin >> x;

    auto diag = vector(N, vector(N, 0ll));
    auto back_diag = vector(N, vector(N, 0ll));

    while (k--) {
        int x, y, p;
        cin >> x >> y >> p;
        x += offset;
        y += offset;
        diag[x - p + 1][y - p + 1] += 1;
        diag[x - p + 2][y - p + 2] += 1;
        diag[x + 1][y + 1] -= 2;
        diag[x + 2][y + 2] -= 2;
        diag[x + 2 + p][y + 2 + p] += 1;
        diag[x + 1 + p][y + 1 + p] += 1;

        back_diag[x - p + 1][(y + 1) + p - 1] -= 1;
        back_diag[x - p + 2][(y + 1) + p - 2] -= 1;
        back_diag[x + 1][(y + 1) - 1] += 2;
        back_diag[x + 2][(y + 1) - 2] += 2;
        back_diag[x + 2 + p][(y + 1) - 2 - p] -= 1;
        back_diag[x + 1 + p][(y + 1) - 1 - p] -= 1;

        // for (int i = x - p + 1; i <= x + 2 + p; i++) {
        //     for (int j = y - p - 1; j <= y + p; j++) {
        //         cout << back_diag[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = x - p + 1; i <= x + 2 + p; i++) {
        //     for (int j = y - p + 1; j <= y + 2 + p; j++) {
        //         cout << diag[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    auto diag_sum = [&](auto &diag) {
        for (int i = 1; i < diag.size(); i++) {
            for (int j = 1; j < diag.size(); j++) {
                diag[i][j] += diag[i - 1][j - 1];
            }
        }
    };
    auto back_diag_sum = [&](auto &back_diag) {
        for (int i = 1; i < back_diag.size(); i++) {
            for (int j = back_diag.size() - 1; j > 0; j--) {
                back_diag[i][j] += back_diag[i - 1][j + 1];
            }
        }
    };
    diag_sum(diag);
    diag_sum(diag);
    back_diag_sum(back_diag);
    back_diag_sum(back_diag);
    auto total = vector(N, vector(N, 0ll));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            total[i][j] = diag[i][j] + back_diag[i][j];
        }
    }
    for (int i = 1; i < N; i++) {
        partial_sum(total[i].begin(), total[i].end(), total[i].begin());
        for (int j = 1; j < N; j++) {
            total[i][j] += total[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            origin[i][j] -= total[i + offset + 1][j + offset + 1];
            if (origin[i][j]) origin[i][j] = max(0ll, origin[i][j]);
            cout << origin[i][j] << ' ';
        }
        cout << endl;
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << total[i + offset + 1][j + offset + 1] << ' ';
    //         // cout << diag[i + offset + 1][j + offset + 1] << ' ';
    //         // cout << back_diag[i + offset + 1][j + offset + 1] << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}