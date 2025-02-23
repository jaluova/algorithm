#include <algorithm>
#include <chrono>
#include <format>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

mt19937 rnd(time(0));

void benchmark(const string &name, const auto &func) {
  auto start = chrono::high_resolution_clock::now();
  func();
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  cout << format("{} execution time: {} ms\n", name, duration.count());
}

int main() {
  vector<int> a = {1, 2, 3, 4};

  do {
    for (auto &x : a) cout << x << ' ';
    cout << endl;
  } while (next_permutation(a.begin(), a.end()));

  return 0;
}