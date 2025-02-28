#ifndef __CLASS__
#define __CLASS__

#include <iostream>
#include <vector>

class bint {
  int size = 0;
  std::vector<int> dig;  // low -> high

 public:
  bint& operator=(const std::string& rhs);
  bint operator+(const bint& rhs);
  friend std::istream& operator>>(std::istream& lhs, bint& rhs);
  friend std::ostream& operator<<(std::ostream& lhs, const bint& rhs);
};

#endif  // __CLASS__