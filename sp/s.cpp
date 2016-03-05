#include <stdio.h>
#include <memory>
#include <iostream>

struct Foo {
  Foo() { std::cout << "Foo::Foo\n"; } 
  ~Foo() { std::cout << "Foo::~Foo\n"; } 
  int i;
  void bar() { std::cout << "Foo::bar\n" << i; } 
};

template <typename T>
class SharedPtr {

 public:
  SharedPtr(T *p=nullptr) :_p(p) {
    if (p != nullptr) {
      _cp = (size_t*)malloc(sizeof(size_t));
      *_cp = 1;
    }
  }

  size_t use_count() const {
    if (_cp == nullptr)
        return 0;
    return *_cp;
  }


  ~SharedPtr() {
    DesCount();
    if (use_count() == 0 && _p != nullptr) {
      delete _p;
      _p = nullptr;
      free(_cp);
      _cp = nullptr;
    }
  }
 
  SharedPtr(SharedPtr<T>& o) {
    if (o.use_count() == 0) 
      return;
    o.IncCount();
    _cp = o._cp;
    _p = o._p;
  }

  operator=

 private:
  inline void DesCount() { (*_cp)--; }
  inline void IncCount() { (*_cp)++; }

 private:
  size_t* _cp = nullptr;
  T *_p = nullptr;
};

//pointer
//什么时候增加引用计数
//什么时候减小引用计数
//什么首先释放资源
int main(int argc, char *argv[])
{
  SharedPtr<Foo> s(new Foo);
  SharedPtr<Foo> o(new Foo);
  {
    SharedPtr<Foo> s1(s);
    printf("use_cout:%ld\n", s.use_count());
    printf("use_cout:%ld\n", s1.use_count());
  }

  printf("s:use_cout:%ld\n", s.use_count());
  printf("o:use_cout:%ld\n", o.use_count());

  
  return 0;
}
