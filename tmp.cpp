#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);

  for (auto& x : a) cin >> x;
  int m;
  cin >> m;
  for (int i = 0; i < n; i++) {
    b[(i + m) % n] = a[i];
  }
  for (auto x : b) cout << x << ' ';
  cout << '\n';
}