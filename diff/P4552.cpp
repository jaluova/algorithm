#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    adjacent_difference(a.begin(), a.end(), a.begin());
    a[0] = 0;
    auto pos = 0ll, neg = 0ll;
    for (auto& x : a) {
        // cout << x << ' ';
        if (x > 0)
            pos += x;
        else
            neg -= x;
    }

    cout << max(pos, neg) << endl;
    cout << abs(pos - neg) + 1 << endl;

    return 0;
}