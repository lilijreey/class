#include <stdlib.h>
#include <stdio.h>
//#include <new>
char buf[1000];

//void* operator new(size_t sz) {
    //printf("global op new called, size = %zu\n",sz);
    //return malloc(sz);
//}
//void operator delete(void* ptr) {
    //printf("global op delete called");
    ////ptr = nullptr;
    //free(ptr);
//}

struct A {
  int i;
  A(int i=0) :i(i){printf("A::A\n");}
  ~A() {
    printf("A::~A\n");
  }
  void show() { printf("A::i:%d\n",i); 
  }

static void* operator new(size_t sz) {
    printf("A::new called, size = %zu\n",sz);
    return malloc(sz);
}
static void operator delete(void* ptr) {
    printf("A::delete called");
    //ptr = nullptr;
    free(ptr);
}

};
constexpr int aa(int i) {return i * sizeof(A);}

int main() {
     int* p1 = new int;
     delete p1;

     void * p = operator new(3);
     printf("%p\n", p);

     //A* p2 = new A[10]; 
     A* p2 = new A(3);
     p2->show();
     delete p2;
     //char ff[aa(10)];

     ////A *b = (A *)malloc(100);

     ////new(b) A(3);

     //A* pn = new(ff) A(4);
     //((A*)&ff)->show();
     //printf("%d\n" *((int*)&ff));

     //A* p2 = new(ff+sizeo(A)) A(4);
     //((A*)&ff)->show();



}
