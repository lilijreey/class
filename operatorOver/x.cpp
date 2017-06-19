
#include <string>
#include <iostream>
#include <cstdio>
class cs 
{
 public:
  cs(int i):_i(i) { printf("cs()_i %d\n", _i); }
  ~cs() { printf("~cs():%d\n", _i); }
  cs& operator=(const cs &o) {
    printf("operator= %d\n", o._i);
    _i = o._i;
    return *this;
  }

  int get_i() const { return _i; }
  int set_i(int i) { return _i; }
 private:
  int _i;
};

cs get_cs() {
  static int i = 0;
  return cs(i++);
}

//class Person {
//  std::string name;
//public:
//  Person(const char* c) :name(c){
//    printf("Perosn(const char)\n");
//  }
//  Person& operator=(const Person &o) {
//    printf("operator =\n");
//    if (this == &o)
//      return *this;
//    return *this;
//  }
//
//  void show() const {
//    std::cout << name << std::endl;
//  }
//
//};

class Date {
private:
  int year=1970;
  int month=1;
  int day {1};
public:
  ~Date() {
    printf("~Date\n");
  }
  void show() const {
    printf("y:%d m:%d d:%d\n", year, month, day);
  }
  Date():year(1970), month(1), day(4) {}
  //Date(int y, int m, int d) {
    //year = y;
    //month = m;
    //day = d;
  //}
};

class Person {
private:
  int age;
  std::string name;
public:
  Person(int a, const std::string &n)
 :age(a), name(n) {
  }

  void setAge(int age) {
    this->age = age;  
  }
  void show() const {
    printf("age:%d name:%s\n", age, name.c_str());
  }
};

int main() {
  Person p(12, "xx");
  p.show();
  p.setAge(18);
  p.show();
  Person::show();
  //Date a;
  //a.Data();
  //a.show();
  //a.~Date();
  //Person x =p;
}



//int main(int argc, char *argv[])
//{
  ////(get_cs() = cs(2)).set_i(323);
  ////get_cs() = cs(2);
  ////get_cs().operator=( get_cs().set_i(32));
  //return 0;
//}
