#include <bits/stdc++.h>

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    const int MOD = 998244353;
    int T, id;
    cin >> T >> id;
    while (T--) {
        int n, m, c, f;
        cin >> n >> m >> c >> f;
        auto a = vector(n, vector<int>(m, 0));
        auto r = vector(n, vector<int>(m + 1, 0));
        auto d = vector(n + 1, vector<int>(m, 0));
        auto u = vector(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int j = 0;
            for (int j = 0; j < m; j++) a[i][j] = 1 - (s[j] - '0');
        }
        // for (int i = 0; i < n; i++) {
        //     partial_sum(a[i].rbegin(), a[i].rend(), r[i].rbegin(),
        //                 [](int prev, int cur) {
        //                     if (cur)
        //                         return prev + cur;
        //                     else
        //                         return 0;
        //                 });
        // }
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i][j] == 1) {
                    r[i][j] = r[i][j + 1] + 1;
                }
            }
        }
        // for (int j = 0; j < m; j++) {
        //     for (int i = n - 1; i >= 0; i--) {
        //         if (i == n - 1) {
        //             d[i][j] = a[i][j];
        //             continue;
        //         }
        //         if (a[i][j])
        //             d[i][j] = a[i][j] + d[i + 1][j];
        //         else
        //             d[i][j] = 0;
        //     }
        // }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    d[i][j] = d[i + 1][j] + 1;
                }
            }
        }
        // for (int j = 0; j < m; j++) {
        //     u[0][j] = max(r[0][j] - 1, 0);
        //     for (int i = 1; i < n; i++) {
        //         if (a[i][j])
        //             u[i][j] = max(r[i][j] - 1, 0) + max(r[i - 1][j] - 1, 0);
        //         else
        //             u[i][j] = 0;
        //     }
        // }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    if (i) u[i][j] = u[i - 1][j];
                    u[i][j] += r[i][j] - 1;
                }
            }
        }

        // for (auto row : d) {
        //     for (auto x : row) cout << x << " ";
        //     cout << endl;
        // }
        // cout << endl;
        // for (auto row : u) {
        //     for (auto x : row) cout << x << " ";
        //     cout << endl;
        // }

        long long vc = 0, vf = 0;
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (a[i][j] == 0 || a[i - 1][j] == 0) continue;
                long long D = d[i][j] - 1;
                long long R = r[i][j] - 1;
                long long U = u[i - 2][j];
                vf += D * R * U * 1ll;
                vc += R * U * 1ll;
                vf %= MOD;
                vc %= MOD;
            }
        }

        cout << vc * c << " " << vf * f << endl;
    }
    return 0;
}