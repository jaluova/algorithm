#include <algorithm>
#include <chrono>
#include <deque>
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
  int n = 100000000;
  deque<int> dq;
  vector<int> v;

  benchmark("push_back", [&]() {
    for (int i = 0; i < n; i++) dq.push_back(rnd());
  });
  benchmark("vector push_back", [&]() {
    for (int i = 0; i < n; i++) v.push_back(rnd());
  });
  benchmark("access", [&]() {
    for (int i = 0; i < n; i++) dq[i] = i;
  });
  benchmark("vector access", [&]() {
    for (int i = 0; i < n; i++) v[i] = i;
  });

  return 0;
}