#include <iostream>
#include <vector>

using namespace std;

struct Student {
  int score;
  string name;
};

int main() {
  auto b = make_tuple(80, 8, "ja1u0va");
  string name;
  int score, id;
  tie(score, id, name) = b;
  cout << score << ' ' << id << ' ' << name << endl;
}