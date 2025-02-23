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
  benchmark("aaa", []() { cout << "hello world!" << endl; });
  vector<int> a = {1, 1, 4, 5, 1, 4};

  ranges::sort(a, [](int a, int b) { return a < b; });

  for (auto &x : a) cout << x << ' ';

  cout << '\n';

  return 0;
}