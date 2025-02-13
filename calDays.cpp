#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int dayInMonths[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int y) {
    if (y % 100 != 0 && y % 4 == 0) {
        return 1;
    }
    if (y % 400 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int y = 1970, m = 1, d = 20;
    int days = 666;
    days += d;
    for (;; ++y) {
        int dayInYear = 365 + isLeapYear(y);

        if (days >= dayInYear)
            days -= dayInYear;
        else
            break;
    }
    for (;; ++m) {
        int dayInMonth = dayInMonths[m] + (m == 2 && isLeapYear(y));
        if (days >= dayInMonth)
            days -= dayInMonth;
        else
            break;
    }

    cout << y << "." << m << "." << days << endl;

    return 0;
}