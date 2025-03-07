#include <cstring>
#include <iostream>
using namespace std;

class People {
 public:
  void display();
  void setname(char* name);
  void setage(int age);
  People(char* name, int age);
  People();

 private:
  char* name;
  int age;
};

People::People() { cout << "无参数的构造函数被调用" << endl; }

inline void People::display() {
  cout << "Name: " << name << ", Age:" << age << endl;
}

inline void People::setname(char* name) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

void People::setage(int age) { this->age = age; }

class A {
 public:
  A(int x1) : x(x1), rx(x), pi(3.14) {}
  void print() { cout << "x=" << x << " rx=" << rx << " pi=" << pi << endl; }

 private:
  int& rx;
  int x;
  const float pi;
};

class D {
 public:
  D(int i) : m2(i), m1(m2 + 1) {
    cout << m1 << endl;
    cout << m2 << endl;
  }

 private:
  int m1;
  int m2;
};

class Coord {
 public:
  Coord(int a, int b) {
    x = a, y = b;
    cout << this->x << "的构造函数执行" << endl;
  }
  // Coord() { cout << "构造函数执行" << endl; }
  ~Coord() { cout << this->x << "的析构函数执行" << endl; }

 private:
  int x;
  int y;
};

int main() {
  // People p1("zhangsan", 12);
  // People p;
  // char name[] = "zhangsan";
  // p.setname(name);
  // p.setage(25);
  // p.display();

  // A a(10);
  // a.print();

  // D d(15);

  Coord c(1, 5);
  Coord c1(3, 6);
}