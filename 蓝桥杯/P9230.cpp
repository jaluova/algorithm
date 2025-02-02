// P9230 [蓝桥杯 2023 省 A] 填空问题
// A 幸运数
// B 有奖回答
#include <iostream>
// #include <vector>

using namespace std;

int main() {
    int cnt = 0;
    for (int i = 1; i <= 100000000; i++) {
        int digitCnt = [](int x) {
            int cnt = 0;
            for (; x; x /= 10, cnt++);
            return cnt;
        }(i);
        if (digitCnt & 1) continue;
        if ([](int x, int digitCnt) {
                int half = digitCnt >> 1;
                int sumL = 0, sumR = 0;
                for (int i = 0; x; ++i, x /= 10) {
                    if (i < half)
                        sumL += x % 10;
                    else
                        sumR += x % 10;
                }
                return sumR == sumL;
            }(i, digitCnt)) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}

// vector<int> num;
// int len = 2;
// void add(vector<int>& a) {
//     a[0] += 1;
//     int i = 0;
//     for (; a[i] >= 10; a[i] %= 10, a[++i] += 1);
//     if (i >= len) {
//         len = i + 1;
//     }
// }
// void mul(vector<int>& a) {
//     a[len] = 1;
//     for (int i = len - 1; i >= 0; --i) a[i] = 0;
//     ++len;
// }

// int sum(vector<int>& a, int l, int r) {
//     int s = 0;
//     for (int i = l; i <= r; ++i) {
//         s += a[i];
//     }
//     return s;
// }

// bool isLucky(vector<int>& a) {
//     if (len & 1 == 1) {
//         mul(a);
//         return false;
//     }
//     if (sum(a, 0, len / 2 - 1) == sum(a, len / 2, len - 1))
//         return true;
//     else
//         return false;
// }

// char pid;
// int main() {
//     int cnt = 0;
//     num = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
//     len = 2;
//     while (num[8] != 1) {
//         if (isLucky(num)) {
//             cnt++;
//             // for (auto& x : num) {
//             //     cout << x;
//             // }
//             // cout << endl;
//         }
//         add(num);
//     }
//     cout << cnt << endl;

//     return 0;
// }