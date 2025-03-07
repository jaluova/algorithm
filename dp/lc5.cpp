#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  int begin = 0, maxLen = 1;

  auto dp = vector(n, vector(n, false));

  for (int i = 0; i < n; i++) dp[i][i] = true;

  for (int len = 2; len <= n; len++) {
    for (int l = 0; l < n; l++) {
      int r = l + len - 1;
      if (r >= n) {
        break;
      }
      if (s[l] == s[r]) {
        if (len <= 3)
          dp[l][r] = true;
        else
          dp[l][r] = dp[l + 1][r - 1];
      }
      if (dp[l][r] && len > maxLen) {
        maxLen = len;
        begin = l;
      }
    }
  }

  string str = s.substr(begin, maxLen);
  cout << str << endl;
}