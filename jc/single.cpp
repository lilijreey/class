/**
 * @file     single.cpp
 *           
 *
 * @author   lili  <lilijreey@gmail.com>
 * @date     2015年11月14日 17时18分37秒
 * @desc  实现单例模式
 *
 */
#include <stdio.h>

class A {
 public:

  static A& getInstance() {
    printf("getInstance\n");
    if (_p == nullptr) {
      _p = new A();
    }
    return *_p;
  }

 private:
  static A *_p;

 private:
  int i;
  int b;
  
 private:
  A(int i=0, int b=0) :i(i), b(b) 
  {
    printf("A(int, int)\n");
  }
  A(const A&);

 public:
  void show() const {
    printf("this:%p i:%d b:%d\n", this, i, b);
  }
};

A *A::_p = nullptr;

int main(int argc, char *argv[])
{
  A& a = A::getInstance();
  a.show();
  A& b = A::getInstance();
  b.show();

  //A c = A::getInstance();
  //c.show();
  //new A();

  //A a;
  //A b;
  
  return 0;
}
