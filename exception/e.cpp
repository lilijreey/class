#include <assert.h>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <system_error>
#include <stdlib.h>
#include <unistd.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

class EACCES {
};
class EGCS {
};

void test try {
  int fd = open("xx", O_RDONLY);
  read(fd, buf, 3);
  read(fd, buf, 3);
  write(fd, buf, 3);
}catch(EACCES e) {

}catch(EDOM e) {

}

void test {
  int ret, fd;
  ret = open("xx", O_RDONLY);
  if (ret == -1) {
    switch(errno) {
    case EACCES:
      printf("xxxxx\n");
      break;
    case ENOSYS:
      printf("yyy\n");
      break;
    case EDOM:
      printf("zzz\n");
      break;
    }
    exit(0);
  }
  fd = ret;
  ret = read(fd, buf, 3);
  if (ret == -1) {
    switch(errno) {
    case EACCES:
      printf("xxxxx\n");
      break;
    case ENOSYS:
      printf("yyy\n");
      break;
    case EDOM:
      printf("zzz\n");
      break;
    }
    exit(0);
  }
  ret = read(fd, buf, 3);
  if (ret == -1) {
    switch(errno) {
    case EACCES:
      printf("xxxxx\n");
      break;
    case ENOSYS:
      printf("yyy\n");
      break;
    case EDOM:
      printf("zzz\n");
      break;
    }
    exit(0);
  }




};

#if 0
void xx() {
  throw 1;
}
struct Y {
  char *a;
  Y(int size) {
    printf("start Y::Y\n");
    a = (char*)malloc(size);
    xx();
    printf("Y constructor over\n");
  }
  ~Y(){ free(a); printf("~Y()\n"); }
};
struct Z {
  Z() {printf("Z::Z()\n");}
  ~Z() {printf("~Z::Z()\n");}
};
void test() {
  Z z; printf("test1 \n");
  Y y(3); printf("test3 \n");
}
int main(int argc, char *argv[])
{
  try {
    test();
  }
  catch(...) {
    printf("catch exception\n");
  }
  
  return 0;
}
#endif

#if 0
class X {
  public:
  class Trouble {};
  class Small : public Trouble {};
  class Big : public Trouble {};
  void f() try { throw Big(); }
  catch(E e) {}
  catch(int i) {}
  catch(...) {}
};
int i=2;
void i_terminate();
int main() try {
  std::set_terminate(i_terminate);
  printf("%p\n", std::terminate );
  printf("%p\n", abort);

  X x;
  try {
    x.f();
  } 
  catch(int i) {
  }

  printf("lalalalal\n");
  //catch(X::Small) { printf("caugh X::Small\n"); }
  //catch(X::Big) { printf("caugh X::Big\n"); }
  //catch(X::Trouble) { printf("catch X::Trouble\n"); }
}catch(...) {
  printf("main catch\n");
}

void i_terminate() {
  printf("i_terminate :)\n");
}

#endif
#if 0
class Except1 {};
class Except2 {
   public:
   Except2(Except1&) {}
};
void f() { throw Except1(); }
int main() {
  try { f();
  } catch (Except2 e) {
    printf("Except2");
  } catch (Except1 e) {
    printf("Except1");
  }
}

#endif

#if 0

struct E : public std::exception
{ private:
  const char* _whatMsg;
 public:
  E(const char* msg) :_whatMsg(msg) {}
  virtual const char *what() const noexcept override {
    return _whatMsg;
  }
};
void s3() { throw E{"has a error"};printf("xxx"); }
void s2() {
  try {
    s3();
  }catch(...) {
    printf("s3 catch exception\n");
    throw;
  };
}
void s1() {
  try {
    s2();
  }catch(...) {
    printf("s2 catch exception\n");
    throw;
  };
}
void s() {
  try {
    s1();
  }catch(E e){
    printf("%s\n", e.what());
  };
}

int main(int argc, char *argv[])
{
  s();
  
  return 0;
}

#endif

#if 0

namespace XX {
int i;
namespace YY {
int i;
} 
}

struct A {

  A(){}
  //A(const A&) = delete;
 private:
  A(const A&) {}
  void show(int i) {
    if (i > 3) 
      throw std::invalid_argument("i must <= 3");
  }
  int i=3;
};


void ee(int i) {
  switch (i) {
  case 1:
    throw std::out_of_range("out_of_range");
    printf("xxxx\n");
    break;
  case 2:
    throw std::invalid_argument("invalid_argument");
    printf("xxxx\n");
    break;
  default:
    throw i;
    printf("after throw\n");
  }
}

void xx() {
  try {
    ee(2);
  }
  catch(int i) {
    printf("xx catch int :%d\n", i);
  }
  catch(std::out_of_range &e) {
    printf("xx catch out:%s\n", e.what());
  }
  //catch(std::invalid_argument &e) {
    //printf("catch inva:%s\n", e.what());
  //}
  //catch(double i) {
    //printf("catch int :%g\n", i);
  //}
  catch(...) {
    printf("xx catch unknown exception\n");
    throw;
  }
  ;
}

void show(int e) { e=100; }
void show(std::out_of_range e) {
  printf("show: %p\n", &e);
  e.what();
}

//void at(int pos) {
  ////argument check
  //if (pos > 0 && < 10) {
    //arr[pos];
  //}
  //throw std::length_error("pos 超出范围");
//}
int main(int argc, char *argv[])
{
  //printf("12:%d, yy: %d \n", arr[12], y);
  std::exception e;
  printf("%s\n", e.what());

  std::logic_error le("logic xxxx");
  printf("logic_error.what: %s\n", le.what());

  std::out_of_range oe("out_of_range");
  printf("oe: %p\n", &oe);
  show(oe);
  int i =3;
  show(i);



  std::invalid_argument ia("null pointer");
  printf("invalid_argument.what: %s\n", ia.what());

  std::length_error ll("length error");
  printf("length_error.what: %s\n", ll.what());

  std::range_error re("range_error");
  printf("range_error.what: %s\n", re.what());
  //std::system_error se(EDOM, std::system_category());
  std::system_error se(ECHILD, std::system_category());
  printf("system_error.what: %s error:%d\n", 
         se.what(), se.code().value());

  try {
    xx();
  }catch(std::invalid_argument &e) {
    printf("caller catch inva:%s\n", e.what());
  }

  //try {
    //ee(2);
  //}
  //catch(int i) {
    //printf("catch int :%d\n", i);
  //}
  //catch(std::out_of_range &e) {
    //printf("catch out:%s\n", e.what());
  //}
  ////catch(std::invalid_argument &e) {
    ////printf("catch inva:%s\n", e.what());
  ////}
  ////catch(double i) {
    ////printf("catch int :%g\n", i);
  ////}
  //catch(...) {
    //printf("catch unknown exception\n");
    //throw;
  //}
  //;

  printf("xxx\n");
  
  return 0;
}

#endif
