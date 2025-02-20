#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), d;
    for (auto& x : a) cin >> x;

    int len = 1;
    d = {0, a[0]};
    for (int i = 1; i < n; i++) {
        for (auto x : d) cout << x << ' ';
        cout << endl;
        if (a[i] > d[len]) {
            d.push_back(a[i]);
            len++;
        } else if (a[i] < d[len]) {
            auto it = lower_bound(d.begin() + 1, d.end(), a[i]);
            *it = a[i];
        }
    }
    cout << len << endl;

    // cout << *upper_bound(a.rbegin(), a.rend(), 10) << endl;

    return 0;
}