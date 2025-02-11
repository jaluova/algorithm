// leetcode 接雨水
// https://leetcode.cn/problems/trapping-rain-water/description/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int n = height.size();
    vector<int> leftMax(n), rightMax(n);
    partial_sum(height.begin(), height.end(), leftMax.begin(),
                [](int prev, int cur) { return max(prev, cur); });
    partial_sum(height.rbegin(), height.rend(), rightMax.rbegin(),
                [](int prev, int cur) { return max(prev, cur); });

    int ans;
    for (int i = 1; i < n - 1; i++) {
        ans += max(0, min(leftMax[i - 1], rightMax[i + 1]) - height[i]);
    }
    cout << ans << endl;

    return 0;
}