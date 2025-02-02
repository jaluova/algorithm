#include <iostream>
#include <vector>

using namespace std;

vector<int> toDigits(int x, int base) {
    vector<int> digits;
    for (; x; x /= base) {
        int digit = x % base;
        digits.push_back(digit);
    }
    return digits;
}

int toDigit(vector<int> &digits, int base) {
    int x = 0;

    for (int i = digits.size() - 1; i >= 0; --i) {
        x = x * base + digits[i];
    }
    return x;
}

int main() {
    vector<int> digits;
    digits = toDigits(10, 8);
    int digit = toDigit(digits, 8);

    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        cout << *it;
    }
    cout << endl;
    cout << digit << endl;

    return 0;
}