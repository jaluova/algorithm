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
  vector<int> a = {1, 1, 10, 20, 30, 200, 2, 1, 10, -5, -8};

  cout << endl;

  return 0;
}