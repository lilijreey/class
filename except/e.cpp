#include <exception>
#include <stdexcept>
#include <stdio.h>

struct B {
  B(int i=0) :i(i){}
  int i;
};
struct C {
  C(int i=0) :i(i) {}
  C(const B& b) {i = b.i;}
  int i;
};

struct A {
  A() {}
  //private:
  A(const A&) {
    printf("A::const A=\n");
  }
  //A& operator=(const A &o) {
  //printf("A::operator=\n");
  //return *this;
  //}
};




void d() {
  throw A{};
  printf("d()\n");
}
void c() {
  try {
    //d();
    throw B{3};
  } catch(int ) {
    printf("catch int\n");
  } catch( double) {
    printf("catch double\n");
  } 
  catch (C &e) {
    printf("catch B\n");
  }
  catch (B &e) {
    printf("catch B\n");
  }
  catch(...) {
    printf("c:: catch noknown exception\n");
    throw;
  }
  printf("c()");
}

void b() {
  c();
  printf("b()\n");
}

void a() {
  try {
    b();
  } catch( A a) {
    printf("a() catch A\n");
  }
  printf("a()\n");
}


void xxx(int *p) {
  if (p == nullptr)
    throw std::invalid_argument("p is nullptr ");
  *p = 3;
}

int main(int argc, char *argv[])
{
  printf("start\n");
  B b(3);
  C c = b;
  printf("c.i:%d\n", c.i);
  //int a;
  //xxx(nullptr);

  //try 
  //{
    //a();
  //} 
  //catch(int e) {
    //printf("catch int %d\n",e);
  //} 
  //catch(double ) {
  //}
  //catch(...) {

    //printf("throw unknown except\n");
  //}
  //catch(A e) {
    //printf("catch A\n");
  //}

  printf("end\n");

  return 0;
}
