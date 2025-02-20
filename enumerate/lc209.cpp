#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

template <typename M, typename I, typename R, typename U>
void increaseEnumerate(int s, int e, const M& match, const I& insert,
                       const R& remove, const U& update) {
    for (int l = s, r = s; l <= e;) {
        if (l < r && match(l, r - 1)) {
            update(l, r - 2);
            remove(l++, r);
        } else if (r <= e) {
            insert(l, r++);
        } else {
            update(l, r - 1);
            remove(l++, r);
        }
    }
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for (auto& x : nums) cin >> x;
    int ans = INT_MAX;
    int sum = 0;
    bool flag = false;
    increaseEnumerate(
        0, n - 1, [&](int l, int r) { return sum >= t; },
        [&](int l, int r) { sum += nums[r]; },
        [&](int l, int r) { sum -= nums[l]; },
        [&](int l, int r) {
            if (r + 1 == n) return;
            flag = true;
            ans = min(ans, r - l + 2);
        });
    cout << flag ? ans : 0;
    return 0;
}