#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), sum(n + 1, 0);

    for (auto& x : a) cin >> x;

    partial_sum(a.begin(), a.end(), sum.begin() + 1,
                [](int prev, int cur) { return prev ^ cur; });
    unordered_map<int, int> cnt;
    for (auto& x : sum) {
        cnt[x]++;
    }

    long long ans = 0;

    for (auto& [_, v] : cnt) {
        ans += 1ll * v * (v - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}