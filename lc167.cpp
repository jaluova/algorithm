#include <iostream>
#include <vector>

using namespace std;

int main() {
    int target, n;
    cin >> n >> target;
    vector<int> numbers(n);
    for (auto &x : numbers) cin >> x;
    vector<int> ans;
    for (int l = 0, r = n - 1; l < r;) {
        if (numbers[l] + numbers[r] >= target) {
            if (numbers[r] + numbers[l] == target) ans = {l + 1, r + 1};
            r--;
        } else {
            l++;
        }
    }
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}