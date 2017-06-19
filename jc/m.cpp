//多重
//
#include <stdio.h>

struct AA {
  AA() {printf("AA\n");}
};
struct A :AA {
 private:
  int a_i;
 public:
  A(int i) :a_i(i) {printf("A::A(int)\n"); }
  void show() const {printf("A::show\n");}
};
struct BB {
  BB() {printf("BB\n");}
};
struct B: BB {
 private:
  int b_i;
 public:
  B(int i) :b_i(i) {printf("B::B(int)\n"); }
  B(int i, int j) :b_i(i) {printf("B::B(int)\n"); }
  B(int i, double j) :b_i(i) {printf("B::B(int)\n"); }
  void hello() const {printf("B::hello\n");}
};

struct C : B, A
{
  C(int b=0, int a=0) 
  :B(b)
  ,A(a)
  {}
};

struct XX { int o; };
struct X : XX{
  int i; //4
  double d;//8
}; //16

struct YY { int s; };
struct Y :YY{
  bool b; //1
  double c; //8
}; //16
struct Z: X, Y {
  int s;//4 + 4+ 32
};

int main(int argc, char *argv[])
{
  Z z;

  //c.show();
  
  return 0;
}

