#include <stdio.h>
#include <memory>
#include <iostream>
#include "myun.cpp"
struct P {
  int a{};
  double c{};
  void fn() {
    printf("%d:%f\n",a,c);
  }
  ~P(){
    printf("~P()\n");
  }
};

void test() {
  //P *p = new P();
  //p->fn();
  //int i;

  //P *s = p;
  //s->fn();
  //delete p;
  //s->fn();
}

struct Foo {
  Foo() { std::cout << "Foo::Foo\n"; } 
  ~Foo() { std::cout << "Foo::~Foo\n"; } 
  int i;
  void bar() { std::cout << "Foo::bar\n" << i; } 
};
int main() { 
  //Foo *foo = new Foo;
  std::unique_ptr<Foo> p1;
  //Unique_ptr<Foo> p2;
  //p2 = p1;
  p1->bar();

  // p1 owns Foo if (p1) p1->bar(); 
  // //operater bool() 
}
