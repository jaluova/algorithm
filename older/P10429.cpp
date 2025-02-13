// 蓝桥杯 拔河
#include <climits>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    vector<long long> sum(n + 1);
    partial_sum(a.begin(), a.end(), sum.begin() + 1);
    multiset<long long> comb;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            comb.insert(sum[j] - sum[i - 1]);
        }
    }
    auto ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        // remove
        for (int j = i; j <= n; j++) {
            comb.erase(comb.find(sum[j] - sum[i - 1]));
        }
        for (int j = 1; j <= i; j++) {
            auto target = sum[i] - sum[j - 1];
            auto iter = comb.lower_bound(target);
            if (iter != comb.end()) {
                // >= target
                ans = min(ans, abs(target - *iter));
            }
            if (iter != comb.begin()) {
                iter--;
                ans = min(ans, abs(target - *iter));
            }
        }
    }
    cout << ans << endl;

    return 0;
}

// brute
// O(N^4)
// for l1
// for r1
// for l2
// for r2

// better
// Memory ->O(N^2)
// Time   ->O(N^2 * log(N))
// for l1
//      remove all comb l2 < l1
// for r1
// sum(l1, r1)
// find the nearest sum
// find x lower_bound in container
// this is multiset
// [l1, r1] < [l2, r2]
// [    ]
//   [      ]
// [ ]  [  ]