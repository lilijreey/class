#include <stdio.h>
#include <iostream>


struct Mammals {
  virtual void run()=0;
  virtual ~Mammals(){}
  int head;
};
struct Pig : virtual Mammals {
  virtual void run() {printf("Pig::run()\n"); }
};
struct Human :virtual Mammals {
  virtual void run() {printf("Human::run()\n"); }
};
struct ZR: Human, Pig {
  virtual void run() {printf("ZR::run()\n"); }
};
int main(){
  Pig p;
  Human h;
  Mammals *m;
  m = &p; m->run();
  m = &h; m->run();
  ZR zr;
  m = &zr;
  m->run();
}

#if 0

class LineList {
  virtual push_back = 0;
  virtual push_front = 0;

  virtual pop_back = 0;
  virtual pop_front = 0;
};

class X : LineList, OO , OYY , ZZ{

}
class SeqList {

}




struct Mammals {
  virtual void run()=0;
  virtual ~Mammals(){}
  int head;
  Mammals() {printf("Mammals::Mammals\n");}

};
struct Pig : virtual Mammals {
  virtual void run() {printf("Pig::run()\n"); }
  int p;
  Pig() {printf("Pig::Pig\n");}
};

struct Human : virtual Mammals {
  virtual void run() {printf("Human::run()\n"); }
  int h;
  Human() {printf("Human::Human\n");}
};

struct X {
  X(){printf("X::X\n");}
};

struct ZR: X , public Human, public Pig {
  ZR(){printf("ZR::ZR\n");}
  virtual void run() {printf("ZR::run()\n"); }
};

int main(int argc, char *argv[])
{
  printf("sizeof(Pig) :%lu\n", sizeof(Pig));
  printf("sizeof(Human) :%lu\n", sizeof(Human));
  printf("sizeof(ZR) :%lu\n", sizeof(ZR));
  ZR zr;
  zr.head =1;
  //printf("zr.head:%d;\n", zr.head);
  //printf("zr.Pig::head:%d;\n", zr.Pig::head);
  //printf("zr.Human::head:%d;\n", zr.Human::head);
  
  return 0;
}


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
  virtual void xx();
  void show() {printf("N::show\n");}
};
struct M{
  M(int i) :a(i) {}
  void vv() {printf("M::vv\n");}
  virtual void xx();

  int a;
};
struct X : N , M 
{
  X(int n=0, int m=0, int x=0) : N(n), M(m), x(x) {}
  int x;
  virtual void xx() {}

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
  x.a
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
