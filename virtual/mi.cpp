/**
 * MI
 */
#include <stdio.h>
class A {
  int i;
  bool a_b; 
 public:
  A() {printf("A::A\n");}
};
class BB {
 public:
  int bb;
  double x;
  BB() {printf("BB::BB\n");}
};
class  B: public BB {
 public:
  B() {printf("B::B\n");}
  int b;
};
class C : public A, public B {
 public:
  int c;
  C(){ printf("C::C\n"); }
};

class D {
  int i;
  bool a_b; 
  int bb;
  double x;
  int b;
  int c;
};


class X {
 public:
  //virtual void show() {
    //printf("X::show\n");
  //}

  void x1() { printf("X::%s\n", __func__);}
  void x2() {  printf("X::%s\n", __func__);}
};
class Y {
 public:
  virtual void y1() { printf("Y::%s\n", __func__);}
  virtual void y2() { printf("Y::%s\n", __func__);}
  //virtual void show() {
    //printf("Y::show\n");
  //}
};

//Mix In
class N : public X, public Y
{
 public:
  virtual void x1() { printf("N::x1\n");}
  virtual void y1() { printf("N::y1\n");}

  //using X::show;
  //using Y::show;
  //void show() {
    ////X::show();
    //Y::show();
  //}
  //void show();
  //void show();
};

int main(int argc, char *argv[])
{
  N n;
  //n.y1();
  //n.y2();
  //n.x1();
  //n.x2();
  X *px = &n;
  px->x1();
  px->x2();

  Y *py = &n;
  py->y1();
  py->y2();
  //px->y1();
  //px->y2();
  //n.X::show();
  //n.Y::show();
  printf("sizeof N %lu\n", sizeof(n));
  C c;
  //A,BB, B, C
  //8 16 24  40
  //8 16 24  32
  printf("sizeof D %lu\n", sizeof(D));
  printf("sizeof C %lu\n", sizeof(C)); printf("sizeof A %lu\n", sizeof(A));
  printf("sizeof BB %lu\n", sizeof(BB)); printf("sizeof B %lu\n", sizeof(B));

  
  return 0;
}
