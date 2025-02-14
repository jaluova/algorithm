// P10424 [蓝桥杯 2024 省 B] 好数
#include <iostream>

using namespace std;

int main() {
    int N, cnt = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        // 因为只调用一次，所以可作为匿名函数
        if ([](int x) {
                for (int odd = 1; x; x /= 10, odd ^= 1) {
                    if ((x & 1) != odd) {
                        return false;
                    }
                }
                return true;
            }(i))
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}
