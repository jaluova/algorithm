#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n = 10;
    int target = 100;
    vector<int> a(n);

    iota(a.begin(), a.end(), 1);
    partial_sum(a.begin(), a.end(), a.begin());
    partial_sum(a.begin(), a.end(), a.begin());

    cout << lower_bound(a.begin(), a.end(), target) - a.begin() << endl;

    return 0;
}

// const int NUM = 20230610;
// int ans = 0;
// vector<int> sum(10000, 0);
// vector<int> cnt(10000, 0);

// while (1) {
//     ans++;
//     sum[ans] = sum[ans - 1] + ans;
//     cnt[ans] = cnt[ans - 1] + sum[ans];
//     printf("%d %d\n", cnt[ans], ans);
//     if (cnt[ans] > NUM) break;
// }

// cout << ans - 1 << endl;