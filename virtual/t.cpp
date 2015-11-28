#include <stdio.h>
#include <typeinfo>
class XZ {
 public:
  int ii;
  double dd;
  virtual ~XZ() {printf("~XZ\n");}
  virtual void aa() { printf("XZ::aa()\n");}
  virtual void area() = 0;
};
class Ract : public XZ {
 public:
  ~Ract() {printf("~Ract\n");}
  void area() { printf("Ract::area\n"); }
  virtual void aa() { printf("Ract::aa()\n");}
  void xx() {}
};
class Circle: public XZ {
 public:
  ~Circle() {printf("~Circle\n");}
  void area() { printf("Circle::area\n"); }
  void yy() {}
  virtual void cc() {printf("Circle::cc");}
};

class A {
 public:
  int a;
  virtual void show() {printf("show\n");};
  void aa() {printf("aa\n");};
  static void xxx() {printf("xxx\n");};
};



int main()
{
  printf("%lu\n", sizeof(A));
  //a.show();
  //void (*aa)() = A::xxx;
  //aa();
////void (*)   ()
////void (A::*)()
  //void (A::*cc)()=  &A::aa;
  //(a.*cc)();
  //(a.*cc)();

  //int i;
  ////static_cast
      ////dynamic_cast<


  //printf("%s\n", typeid(i).name());
  //printf("%s\n", typeid(a).name());
  
  ////printf("%p\n", &A::show);
  ////printf("%p\n", &A::aa);
  ////printf("%p\n", A::xxx);
  //return 0;
}
