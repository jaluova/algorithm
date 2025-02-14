// 蓝桥杯 重新排序
#include <algorithm>
#include <iostream>
#include <numeric>
// #include <set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;
    vector<long long> sum(n + 1);
    partial_sum(a.begin(), a.end(), sum.begin() + 1);
    cin >> m;
    long long total = 0;
    vector<long long> diff(n + 2);
    while (m--) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
        total += sum[r] - sum[l - 1];
    }
    partial_sum(diff.begin(), diff.end(), diff.begin());
    sort(diff.begin(), diff.end(), greater<long long>());
    sort(a.begin(), a.end(), greater<long long>());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * diff[i];
    }
    cout << ans - total << endl;

    return 0;
}
// int n, m;
// cin >> n;

// vector<int> a(n, 0), sum(n + 1, 0);

// for (int i = 0; i < n; i++) cin >> a[i];
// partial_sum(a.begin(), a.end(), sum.begin() + 1);

// long long pre = 0;
// cin >> m;
// auto memory = vector(m, vector<int>(2));
// vector<int> cnt(n + 2);
// for (int i = 0; i < m; i++) {
// int l, r;
// cin >> l >> r;
// memory[i][0] = l, memory[i][1] = r;
// cnt[l] += 1, cnt[r + 1] -= 1;
// pre += sum[r] - sum[l - 1];
// }

// partial_sum(cnt.begin(), cnt.end(), cnt.begin());

// sort(a.begin(), a.end());

// vector<int> b(n + 1);
// for (int i = n - 1; i >= 0; i--) {
// auto it = max_element(cnt.begin(), cnt.end());
// int pos = distance(cnt.begin(), it);
// cnt[pos] = -1;
// b[pos] = a[i];
// }
// partial_sum(b.begin(), b.end(), b.begin());

// long long cur = 0;
// for (int i = 0; i < m; i++) {
// int l, r;
// l = memory[i][0], r = memory[i][1];
// cur += b[r] - b[l - 1];
// }
// cout << cur - pre << endl;