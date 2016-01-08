
#include <stdio.h>
#include <stdlib.h>
#include <exception>

struct A {
  A(int l) {}
  int len;
  //char *buf;
  //A(int len){
    //char *p= malloc(len);
    //if (NULL == buf) {
      //throw std::bad_alloc;
    //}

    //buf = p;
    //char *p= malloc(len);
    //if (NULL == buf) {
      //free(p)
      //throw std::bad_alloc;
    //}
    //buf = p;

    //printf("A::start i:%d\n",i);
    //if (i > 3) 
      //throw i;
    //printf("A::end\n");
  };
  //~A() {
    //free(buf);
    //printf("A::~() i:%d\n", i);
  //}
//void ok() noexcept {
  //printf("ok\n");
//}

struct D {
  virtual void ok() {
    printf("ok\n"); 
  }
  virtual void ok() noexcept{
    printf("ok\n");
  }

  void cc(int *) {}
  void cc(const int *) {}

};

struct F : D {
  virtual void ok() noexcept {
    printf("ok\n");
  }
};

void ok(int i) throw(int, double)
{
  switch (i) {
  case 1:
    throw 3;
  case 2:
    throw 3.23;
  case 3:
    throw A(3);
  }

  throw 3;

}

int main(int argc, char *argv[])
{
  
  return 0;
}


#if 0


void oo() {
  A a(2);
  A b(5);
  printf("oo\n");
}

struct MutexScope {
  //Mutex() {
    //m.lock();
  //}
  //pthread_mutex m;
  //~Mutex() {
    //m.unlock();
  //}
};

int main(int argc, char *argv[])
{
  //list l;
  //pthread_mutex m;
  //m.lock();
  //l.insert(3);
  //m.unlock();
  //

//RAII
 //{ MutexScope mc;
  //l.insert(3);
 //}


  try {
    oo();
  }
  catch(...) {
  }
  printf("ok\n");

  
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
  //
  
//}
#endif 
