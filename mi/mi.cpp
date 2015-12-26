#include <stdio.h>

#include <iostream>
istream: ios
ostream: ios



struct X {
  virtual ~X() {}
  virtual void show() {
    printf("X::show\n");
  }
  virtual void x() {
    printf("X::x\n");
  }
};
struct Y {
  virtual ~Y() {}
  virtual void show() {
    printf("Y::show\n");
  }
  virtual void y() {
    printf("Y::y\n");
  }
};
struct A: X, Y {
  virtual void show() {
    printf("A::show\n");
  }
  virtual void x() {
    printf("A::x\n");
  }
  virtual void y() {
    printf("A::y\n");
  }
};

int main(int argc, char *argv[])
{
  A a;
  X *px = &a;
  px->x();
  Y *py = &a;
  y->y();


  printf("%lu\n",sizeof(X));
  printf("%lu\n",sizeof(Y));
  printf("%lu\n",sizeof(A));
  
  return 0;
}

#if 0

int main(int argc, char *argv[])
{
  A a;
  X *px = &a;
  px->show();
  px->x();

  Y *py = &a;
  py->show();
  py->y(); 



  
  return 0;
}

struct A {
  int a_i;
  double a_b;
};
struct O {
  int o_i;
};

struct B : O, A {
  double b_i;
  int b_b;
};

struct N{
  N(int i) :a(i) {}
  int a;
  void show() {printf("N::show\n");}
};
struct M{
  M(int i) :a(i) {}
  void vv() {printf("M::vv\n");}

  int a;
};
struct X : N , M 
{
  X(int n=0, int m=0, int x=0) : N(n), M(m), x(x) {}
  int x;

  //void show() {printf("N::show\n");}
  void show(int ) {printf("X::show\n");}
  using N::show;
  using N::a;
};


int main(int argc, char *argv[])
{
  X x;
  X y(1,3,4);
  //x.show(3);
  //x.show();
  //x.N::a = 3;
  //x.M::a = 3;

  printf("%lu\n", sizeof(X));
  printf("%lu\n", sizeof(B));
  printf("%lu\n", sizeof(O));
  
  return 0;
}
struct A {
  A() {printf("A::A\n");}
  ~A() {printf("A::~A\n");}
  int a_i;
  double a_b;
};
struct O {
  ~O() {printf("O::~O\n");}
  O() {printf("O::O\n");}
  int o_i;
};
struct B :O {
  ~B() {printf("B::~B\n");}
  B() {printf("B::B\n");}
  int b_i;
  bool b_d;
};
struct C : public A, B  {
  C() {printf("C::C\n");}
  ~C() {printf("C::~C\n");}
  double c;
} ;

int main(int argc, char *argv[]) {
  C c;
  
  return 0;
}
#endif
