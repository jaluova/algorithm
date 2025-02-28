#include "bint.h"

bint& bint::operator=(const std::string& rhs) {
  if (dig.size()) dig.clear();
  size = rhs.size();
  dig.resize(size);
  for (int i = 0; i < size; i++) {
    dig[i] = rhs[size - 1 - i] - '0';
  }

  return *this;
}

bint bint::operator+(const bint& rhs) {
  bint ret;
  ret.size = std::max(rhs.size, size) + 1;
  ret.dig.resize(ret.size);
  for (int i = 0; i < ret.size - 1; i++) {
    if (i < size) ret.dig[i] += dig[i];
    if (i < rhs.size) ret.dig[i] += rhs.dig[i];
    if (ret.dig[i] >= 10) {
      ret.dig[i + 1]++;
      ret.dig[i] -= 10;
    }
  }
  while (ret.dig[ret.size - 1] == 0 && ret.size > 1) ret.size--;

  return ret;
}

std::istream& operator>>(std::istream& lhs, bint& rhs) {
  std::string str;
  lhs >> str;
  rhs = str;
  return lhs;
}

std::ostream& operator<<(std::ostream& lhs, const bint& rhs) {
  for (int i = rhs.size - 1; i >= 0; i--) {
    lhs << rhs.dig[i];
  }
  return lhs;
}