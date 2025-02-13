// P8740 [蓝桥杯 2021 省 A] 填空问题
// A 卡片
// B 直线

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0;
    vector<int> cards(10, 2021);

    for (; [&](int x) {
             for (; x; x /= 10) {
                 if (cards[x % 10] >= 1)
                     cards[x % 10]--;
                 else
                     return false;
             }
             return true;
         }(num);
         num++);

    cout << num - 1 << endl;

    return 0;
}