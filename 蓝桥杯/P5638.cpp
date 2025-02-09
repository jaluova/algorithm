#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    // n--;
    vector<long long> a(n);
    vector<long long> sum(n + 1);
    for (auto &x : a) cin >> x;
    partial_sum(a.begin(), a.end(), sum.begin() + 1);
    long long total = accumulate(a.begin(), a.end(), 0ll);
    printf("total:%lld\n", total);
    k = min(k, n - 1);
    long long ans = total;
    for (int i = k; i < n; i++) {
        ans = min(ans, total - (sum[i] - sum[i - k]));
    }

    cout << ans << endl;

    return 0;
}

// int n, k;
// long long max = 0;
// cin >> n >> k;
// vector<long long> a(n);
// for (int i = 1; i <= n - 1; i++) cin >> a[i];

// partial_sum(a.begin() + 1, a.end(), a.begin() + 1);

// for (int i = 1; i <= n - k + 1; i++) {
//     int upper = i + k - 1;
//     long long tmp = a[upper] - a[i - 1];
//     if (tmp > max) max = tmp;
// }

// cout << a[n - 1] - max << endl;