#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> m(n);
    int ans = 0;
    for (auto& x : a) cin >> x;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) m[i] = max(m[i], m[j]);
        }
        ans = max(ans, ++m[i]);
    }
    cout << ans << endl;
    return 0;
}