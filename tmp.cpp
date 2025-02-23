#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  double a = 0.2;
  cout << setprecision(2) << fixed << a;

  return 0;
}