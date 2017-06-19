#include <stdio.h>

struct A {
  int i;
  void show() {printf("A::show()\n");}
  virtual void vv() {printf("A::vv()\n");}
  virtual void vv2() {printf("A::vv2()\n");}
  virtual ~A(){}
};

int main() {
  A a;

  printf("_vptr:%p\n", *((void **)&a));
  printf("vv:%p\n", &A::vv);
  printf("vv:%p\n", &A::vv2);
  printf("vv:%p\n", &A::show);

  a.show();
  a.vv();

  printf("pass\n");

}
