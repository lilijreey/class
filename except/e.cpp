
#include <stdio.h>
struct A {
  A() {}
private:
  A(const A&) {
    printf("A::const A=\n");
  }
  //A& operator=(const A &o) {
    //printf("A::operator=\n");
    //return *this;
  //}
};

int main(int argc, char *argv[])
{
  printf("start\n");
  int i;
  A a;
  throw a;
  printf("end\n");
  
  return 0;
}
