// 蓝桥杯 挖矿
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int s = 1e7;
    int n, m;
    vector<int> a(2 * s, 0);
    cin >> n >> m;
    while (n--) {
        int x;
        cin >> x;
        a[x + s]++;
    }
    partial_sum(a.begin(), a.end(), a.begin());
    int ans = 0;
    for (int f = 0; f <= m; f += 2) {
        int l = s - f / 2;
        int r = s + (m - f);
        ans = max(ans, a[r] - a[l - 1]);
        l = s - (m - f);
        r = s + f / 2;
        ans = max(ans, a[r] - a[l - 1]);
    }
    cout << ans << endl;
    return 0;
}