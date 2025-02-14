#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    auto colors = vector(3, vector<int>(n + 1));

    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        colors[k - 1][l] += 1;
        colors[k - 1][r + 1] -= 1;
    }

    for (auto& color : colors)
        partial_sum(color.begin(), color.end(), color.begin());

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (colors[0][i] != 0 && colors[1][i] != 0 && colors[2][i] == 0) ans++;

    cout << ans << endl;

    return 0;
}

// 0   白
// 1   黄
// 10  蓝
// 100 红
// 11~99 绿

// int n, m;
// cin >> n >> m;
// vector<int> a(n + 1, 0), sum(n + 1, 0);
// // for (int i = 1; i <= n; i++) {
// //     cin >> a[i];
// // }

// while (m--) {
//     int l, r, k;
//     cin >> l >> r >> k;
//     l--;
//     r--;
//     if (k == 1) {
//         sum[l] += 1;
//         sum[r + 1] -= 1;
//     } else if (k == 2) {
//         sum[l] += 10;
//         sum[r + 1] -= 10;
//     } else {
//         sum[l] += 100;
//         sum[r + 1] -= 100;
//     }
// }
// partial_sum(sum.begin(), sum.end(), a.begin());

// int ans = 0;
// for (auto &x : a) {
//     if (x == 11) ans++;
//     cout << x << " ";
// }
// cout << endl;
// cout << ans << endl;