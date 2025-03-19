#include <iostream>
#include <vector>

using namespace std;

int main() {
  const int mod = 1e9 + 7;
  string s, t;
  cin >> s >> t;

  int n = s.size();
  int m = t.size();
  vector<int> f(m);
  vector<int> dic[256];
  for (int i = 0; i < m; i++) {
    dic[(int)t[i]].push_back(i);
  }

  for (int i = n - 1; i >= 0; i--) {
    int size = dic[(int)s[i]].size();
    if (size == 0) continue;
    for (int j = 0; j < size; j++) {
      int x = dic[(int)s[i]][j];
      if (x == m - 1)
        f[x] = (f[x] + 1) % mod;
      else
        f[x] = (f[x] + f[x + 1]) % mod;
    }
  }
  cout << f[0] << endl;
}