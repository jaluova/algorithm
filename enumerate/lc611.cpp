#include <algorithm>
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
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& x : nums) cin >> x;
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i + 2 < n; i++) {
        increaseEnumerate(
            i + 1, n - 1,
            [&](int l, int r) { return nums[r] >= nums[l] + nums[i]; },
            [&](int l, int r) {}, [&](int l, int r) {},
            [&](int l, int r) {
                if (r > l) ans += r - l;
            });
    }
    cout << ans << endl;

    return 0;
}
