#include <iostream>
using namespace std;

bool isSecure(string s) {
  // 长度判断
  if (s.length() < 8 || s.length() > 16) return false;
  if (s[0] < 'A' || s[0] > 'Z') return false;
  int lower = 0, num = 0, special = 0;  // 小写字母 数字 特殊符号
  for (auto c : s) {
    if (c >= 'a' && c <= 'z') lower++;
    if (c >= '0' && c <= '9') num++;
    if (c == '~' || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' ||
        c == '*')
      special++;
  }
  if (lower == 0 || num == 0 || special == 0) return false;
  return true;
}

int main() {
  string s;
  cin >> s;
  if (isSecure(s))
    cout << "true" << endl;
  else
    cout << "false" << endl;
}