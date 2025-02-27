#include <iostream>

using namespace std;

class BigInt {
  int* digits = nullptr;
  int size = 0;
  int t = 0;

 public:
  BigInt(const BigInt& x) {
    size = x.size;
    digits = new int[size];
    memcpy(digits, x.digits, 4 * size);
  }
  BigInt(const string& str) : size(str.size()) {
    digits = new int[size];
    // assign str chars to digits
  }
  BigInt(long long x = 0) {}
  ~BigInt() {
    if (digits == nullptr) return;
    delete[] digits;
    digits = nullptr;
  }
  BigInt operator+(const BigInt& x) {
    BigInt ret;
    int maxLen = max(size, x.size);
    ret.digits = new int[maxLen + 1];
    // add self and x to ret
    return ret;
  }
  BigInt& operator+=(const BigInt& x) {
    // add x to self
    return *this;
  }
  BigInt& output() {}

  friend BigInt operator+(int x, BigInt& rhs);
};

BigInt operator+(int x, BigInt& rhs) { rhs.digits; }

int main() {}
