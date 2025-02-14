#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n, m;
    auto a = vector(n, vector<int>(m));
    auto sum = vector(n + 1, vector<int>(m + 1));

    // 先考虑current row，再加上上一行的影响
    for (int i = 1; i <= n; i++) {
        partial_sum(a.begin(), a.end(), sum[i].begin());
        for (int j = 1; j <= m; j++) {
            sum[i][j] += sum[i - 1][j];
        }
    }

    // 根据周边的几块，利用容斥原理
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] =
                a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    auto d = vector(n + 1, vector<int>(m + 1));

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            d[i][j] = a[i][j] - a[i - 1][j];
        }
        adjacent_difference(d[i].begin(), d[i].end(), d[i].begin());
    }

    for (int i = n; i >= n; i--) {
        for (int j = m; j >= 1; j--) {
            d[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
        }
    }

    return 0;
}