#include <iostream>
using namespace std;

class A {
 public:
  A(int aa) {
    cout << "A的构造函数被执行" << endl;
    this->a = aa;
  }
  ~A() { cout << "A类析构函数被执行" << endl; }

 private:
  int a;
};

class B {
 public:
  B(int bb) {
    cout << "B类构造函数被执行" << endl;
    this->b = bb;
  }
  ~B() { cout << "B类析构函数被执行" << endl; }

 private:
  int b;
};

class C : public A {
 public:
  C(int aa, int bb, int cc) : A(aa), br(bb) {
    cout << "派生类构造函数被执行" << endl;
  }
  ~C() { cout << "C类析构函数被执行" << endl; }

 private:
  B br;
  int c;
};

int main() {
  C cc(1, 2, 3);
  return 0;
}