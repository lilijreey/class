
#include <stdio.h>

class Base {
  private: int a;
  protected: int b;
  protected: int c;
  public: int d;
};

class D : public Base {
  public: using Base::b;  // protected to public
  private: using Base::c; // protocted to private
  //private:

};

class F : public D {
 public: 
  void show() const {
    printf("%d\n", b);
    //printf("%d\n", c);
  }
};

int main(int argc, char *argv[])
{
  F f;
  printf("%d\n", f.b);
  
  return 0;
}

//class X : public B {...};
//class Y : protected B {...};
//class Z : private B {...};

//class XX : B {...}; // B is a private base
//struct YY : B {...}; // B is a public base
             

//struct Base {
  //private:   int _private=0;
  //protected: int _protected=0; 
  //public:    int _public=0; 
//};

//struct Derive : Base {
//// public:
  //int test() {
    ////1. is can access to _protected?
    //_private = 3;
    //return _protected;
  //}
//};

//int main() {
  //Derive d;
  ////2. is can access to test()?
  //d.test();
  ////3. is can access to _protected?
  ////the different between 1,3 ?
  //d._protected;
//}

//struct A {
  //A() {printf("A::A()\n");}
  //~A() {printf("A::~A()\n");}
//};

//struct B : A  {
  //B() {printf("B::B()\n");}
  //~B() {printf("~B::B()\n");}
//};

//struct C : B  {
  //C() {printf("C::C()\n");}
  //~C() {printf("C::~C()\n");}
//};

//int main() {
  //C c; //output messages order?
//}

//struct B {
  //B() :_b(0) {
    //printf("B()\n");
  //}
  //B(int b) :_b(b) {
    //printf("B(int)\n");
  //}
  //int _b;
//};

//struct C :B {
  //using B::B;
  //C(int i) {
    //printf("C(int i)\n");
  //}
  
  ////C() {
    ////printf("C\n");
  ////}

  //C(int i):B::B(i)  {}

  //void show() {
    //printf("struct C _b: %d\n", _b);
  //}
//};

//struct D :B {
  //using B::B;

  //int _d;
//};
//int main(int argc, char *argv[])
//{
  ////C c;
  //C s(3);
  //s.show();
  
  //D d(4);
  //printf("%d %d\n", d._b, d._d);
  //return 0;
//}
//struct Base {
  //void f(int i) {printf("Base::f %d\n", i);}
//};
//struct Derived : Base {
  ////using Base::f;

  //void f(double i) {printf("Derived::f %f\n", i);}
//};
//void use()
//{
  //Derived d;
  //d.f(1.0); // which functions called?
  //d.f(1);   // which functions called?
//}

//int main(int argc, char *argv[])
//{
  //use();
  
  //return 0;
//}

//class Base {

 //public:
  //void show() const
  //{
    //printf("Base::show()\n");
  //}
//};

//struct A  : Base {
//};

//struct B  : A {
//};


//int main(int argc, char *argv[])
//{
  //A a;
  //B b;
  //a.show();
  //b.show();
  
  //return 0;
//}
