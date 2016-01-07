
#include <stdio.h>
#include <stdlib.h>
#include <exception>

struct A {
  int i;
  A(int i):i(i){
    printf("A::start i:%d\n",i);
    if (i > 3) 
      throw i;
    printf("A::end\n");
  }
  ~A() {
    printf("A::~() i:%d\n", i);
  }
};

void oo() {
  A a(2);
  A b(5);
  printf("oo\n");
}

int main(int argc, char *argv[])
{
  oo();
  
  return 0;
}

void my_terminate(void) {
  printf("unknown except check your code!\n");
}


void xx(int *p) {
  if (p == nullptr)
    throw 0;
  *p = 3;
}

void yy() try {
  xx(nullptr);
  printf("xx()\n");
}catch(int e) {
  printf("catch int\n");
}catch(...) {
  printf("catch unknown exception\n");
}

//int main(int argc, char *argv[])
//{
  //yy();
  //printf("hellow\n");
  //printf("%p, %p\n",
         //std::terminate,
         //abort);
  ////std::set_terminate(my_terminate);
  ////throw 1;
  ////std::terminate();
  ////std::terminate();

  //printf("world\n");
//}
