#include <iostream>

using namespace std;

class BigInt {
  int* digits = nullptr;
  int size = 0;
  int sign = 0;

 public:
  BigInt(const BigInt& x) {
    sign = x.sign;
    size = x.size;
    digits = new int[size];
    memcpy(digits, x.digits, 4 * size);
  }
  BigInt(const string& str, int sign) : sign(sign), size(str.size()) {
    digits = new int[size];
    // assign str chars to digits
  }
  BigInt(long long x = 0) {}
  ~BigInt() {
    if (digits == nullptr) return;
    delete[] digits;
    digits = nullptr;
  }

  BigInt add(const BigInt& x) {
    BigInt ret;
    // add self and x to ret
    return ret;
  }
};

int main() {
  BigInt a("123"s, 1);
  BigInt* ptr = new BigInt("456"s, -1);
  BigInt b = 1000;
  BigInt c = {"789", 1};
  BigInt d;
  BigInt e(a);
}