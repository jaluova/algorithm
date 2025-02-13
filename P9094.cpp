#include <iostream>
#include <vector>

#include "debug.h"
using namespace std;

int main() {
    vector<vector<int>> a = {{1, 1, 4}, {5, 1, 4}};
    vector<int> b = {1, 9, 1, 9, 8, 1, 0};
    DEBUG(a);
    DEBUG(b);
    return 0;
}