#include <iostream>
#include <vector>

class bint {
  int size = 0;
  std::vector<int> dig;  // low -> high

 public:
  bool operator<(const bint& rhs);
  bint& operator=(const std::string& rhs);
  bint operator+(const bint& rhs);
  bint operator-(const bint& rhs);
  bint operator*(const bint& rhs);
  bint operator/(const bint& rhs);
  bint operator%(const bint& rhs);

  friend std::istream& operator>>(std::istream& lhs, bint& rhs);
  friend std::ostream& operator<<(std::ostream& lhs, const bint& rhs);
};

int main() {
  bint a, b;
  std::cin >> a >> b;
  std::cout << a / b << std::endl;
  std::cout << a % b << std::endl;
}

bool bint::operator<(const bint& rhs) {
  if (size != rhs.size) return size < rhs.size;
  for (int i = size - 1; i < size; i++) {
    return dig[i] < rhs.dig[i];
  }
  return false;  // =
}

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

bint bint::operator-(const bint& rhs) {
  bint ret;
  ret = *this;
  for (int i = 0; i < size; i++) {
    if (i < rhs.size) ret.dig[i] -= rhs.dig[i];
    if (ret.dig[i] < 0) {
      ret.dig[i] += 10;
      ret.dig[i + 1]--;
    }
  }
  while (ret.size > 1 && ret.dig[ret.size - 1] == 0) ret.size--;
  return ret;
}

bint operator*(const bint& rhs) {}

bint bint::operator/(const bint& rhs) {
  bint ret;
  ret.dig.resize(size);
  ret.size = size;
  bint res = *this;
  for (int i = size - rhs.size; i >= 0;) {
    int flag = true;
    if (size - i <= rhs.size)
      for (int j = rhs.size - 1; j >= 0; j--) {
        if (dig[j + i] < rhs.dig[j]) {
          flag = false;
          i--;
          break;
        }
        if (dig[j + i] > rhs.dig[j]) break;
      }
    if (flag) {
      for (int j = 0; j < size - i; j++) {
        if (j < rhs.size) dig[j + i] -= rhs.dig[j];
        if (dig[j + i] < 0) {
          dig[j + i] += 10;
          dig[j + i + 1]--;
        }
      }
      while (dig[size - 1] == 0 && size > 1) size--;
      ret.dig[i]++;
    }
  }
  while (ret.dig[ret.size - 1] == 0 && ret.size > 1) ret.size--;
  *this = res;
  return ret;
}

bint bint::operator%(const bint& rhs) {
  bint res = *this, ret;
  for (int i = size - rhs.size; i >= 0;) {
    int flag = true;
    if (size - i <= rhs.size)
      for (int j = rhs.size - 1; j >= 0; j--) {
        if (dig[j + i] < rhs.dig[j]) {
          flag = false;
          i--;
          break;
        }
        if (dig[j + i] > rhs.dig[j]) break;
      }
    if (flag) {
      for (int j = 0; j < size - i; j++) {
        if (j < rhs.size) dig[j + i] -= rhs.dig[j];
        if (dig[j + i] < 0) {
          dig[j + i] += 10;
          dig[j + i + 1]--;
        }
      }
      while (dig[size - 1] == 0 && size > 1) size--;
    }
  }
  ret = *this;
  *this = res;
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