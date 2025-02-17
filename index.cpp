#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;
    int sum = 0;
    int ans = INT_MAX;
    for (int l = 0, r = 0; l < n;) {
        if (r < n && sum < target)
            sum += nums[r++];
        else {
            if (sum >= target) ans = min(ans, r - l);
            sum -= nums[l++];
        }
    }
    cout << ans << endl;

    return 0;
}