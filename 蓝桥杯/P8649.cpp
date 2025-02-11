#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n), sum(n + 1, 0);
    for (auto& x : a) cin >> x;
    partial_sum(a.begin(), a.end(), sum.begin() + 1);

    unordered_map<int, int> cnt;
    for (auto& x : sum) {
        cnt[x % k]++;
    }

    long long ans = 0;
    for (auto& [u, v] : cnt) {
        ans += 1LL * v * (v - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
