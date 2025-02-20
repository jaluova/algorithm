// 商品库存管理
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> range(m);
    vector<long long> cnt(n + 2);
    for (auto& [f, s] : range) {
        cin >> f >> s;
        cnt[f]++;
        cnt[s + 1]--;
    }
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    vector<int> ones(n + 2);
    int zero = 0;

    partial_sum(cnt.begin(), cnt.end() - 1, ones.begin(),
                [&](int prev, int cur) {
                    if (cur == 0) zero++;
                    if (cur == 1) return prev + 1;
                    return prev;
                });

    for (auto& [f, s] : range) cout << ones[s] - ones[f - 1] + zero << endl;

    return 0;
}
// int n, m;
// cin >> n >> m;
// vector<int> a(n + 2);
// auto act = vector(m, vector<int>(2));

// for (int i = 0; i < m; i++) {
//     int l, r;
//     cin >> l >> r;
//     // l--, r--;
//     a[l]++, a[r + 1]--;
//     act[i][0] = l, act[i][1] = r;
// }
// partial_sum(a.begin(), a.end(), a.begin());

// // for (auto x : a) cout << x << " ";
// // cout << endl;
// int zero = 0;
// vector<int> cnt(n + 1);
// for (int i = 1; i <= n; i++) {
//     if (a[i] == 1) cnt[i] += 1;
//     if (a[i] == 0) zero++;
//     cnt[i] += cnt[i - 1];
// }
// // for (auto x : cnt) cout << x << " ";
// // cout << endl;

// for (int i = 0; i < m; i++) {
//     int l = act[i][0], r = act[i][1];
//     cout << cnt[r] - cnt[l - 1] + zero << endl;
// }