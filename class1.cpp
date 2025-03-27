#include <cstring>  // 添加头文件以使用 strcpy
#include <iostream>
using namespace std;

class employer {
 public:
  employer(const char na[10], int le = 1);  // 使用 const 修饰字符数组
  virtual void pay() = 0;                   // 纯虚函数
  void promote(int ll);
  void displayStatus();

 protected:
  char name[10];
  int no;
  int level;
  float money;
  static int count;
};

int employer::count = 1000;  // 初始化静态成员变量

employer::employer(const char na[10], int le) {
  strcpy(name, na);
  no = count++;
  level = le;
}

void employer::promote(int ll) { level += ll; }

void employer::displayStatus() {
  cout << "员工的名字是：" << name << endl;
  cout << "员工的工号是：" << no << endl;
  cout << "员工的级别是：" << level << endl;
  cout << "员工的薪资是：" << money << endl;
}

class technician : public employer {
 public:
  technician(const char na[10], float ho, int worh, int le = 3);
  void pay();

 private:
  float hourlyRate;
  int workHours;
};

technician::technician(const char na[10], float ho, int worh, int le)
    : employer(na, le) {
  hourlyRate = ho;
  workHours = worh;
}

void technician::pay() { money = hourlyRate * workHours; }

class manager : virtual public employer {  // 虚继承
 public:
  manager(const char na[10], float bo, int le = 4);
  void pay();

 protected:
  float bonus;
};

manager::manager(const char na[10], float bo, int le) : employer(na, le) {
  bonus = bo;
}

void manager::pay() { money = bonus; }

class salesman : virtual public employer {  // 虚继承
 public:
  salesman(const char na[10], float com, float sale, int le = 1);
  void pay();

 protected:
  float CommRate;
  float sales;
};

salesman::salesman(const char na[10], float com, float sale, int le)
    : employer(na, le) {
  CommRate = com;
  sales = sale;
}

void salesman::pay() { money = CommRate * sales; }

class salesmanager : public manager, public salesman {
 public:
  salesmanager(const char na[10], float bo, float com, float sale, int le = 3);
  void pay();
};

salesmanager::salesmanager(const char na[10], float bo, float com, float sale,
                           int le)
    : manager(na, bo, le), salesman(na, com, sale, le), employer(na, le) {}

void salesmanager::pay() { money = bonus + CommRate * sales; }

int main() {
  manager mm("Lina", 50000, 4);
  mm.pay();
  mm.displayStatus();

  salesman sa("Zhangsan", 0.04, 200000, 1);
  sa.pay();
  sa.displayStatus();

  salesmanager ss("Lisi", 4000, 0.05, 300000, 3);
  ss.pay();
  ss.displayStatus();

  return 0;
}