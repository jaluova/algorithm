#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int div(vector<int> a, int num) {
    int l = 0, r = a.size() - 1;
    int pos = 0;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m] < num) {
            pos = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
}

int main() {
    // int n;
    // cin >> n;
    // vector<int> a(n), d;
    // for (auto& x : a) cin >> x;

    // int len = 1;
    // d = {0, a[0]};
    // for (int i = 1; i < n; i++) {
    //     for (auto x : d) cout << x << ' ';
    //     cout << endl;
    //     if (a[i] > d[len]) {
    //         d.push_back(a[i]);
    //         len++;
    //     } else if (a[i] < d[len]) {
    //         auto it = lower_bound(d.begin() + 1, d.end(), a[i]);
    //         *it = a[i];
    //     }
    // }
    // cout << len << endl;

    // cout << *upper_bound(a.rbegin(), a.rend(), 10) << endl;
    int n, num;
    cin >> n >> num;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    cout << div(a, num) << endl;

    return 0;
}