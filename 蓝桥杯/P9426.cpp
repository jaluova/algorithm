// https://www.luogu.com.cn/problem/P9426
// 抓娃娃
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int offset = 1e6;

    int n, m;
    cin >> n >> m;
    vector<int> a(offset * 2, 0);
    int l, r;

    while (n--) {
        cin >> l >> r;
        a[l + r]++;
    }
    partial_sum(a.begin(), a.end(), a.begin());
    while (m--) {
        cin >> l >> r;
        cout << a[2 * r] - a[2 * l - 1] << endl;
    }

    return 0;
}