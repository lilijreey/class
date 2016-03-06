#include <string.h>
#include <stdio.h>
#include <stdint.h>

template <typename T>
struct M;

template <typename T>
struct M<T*> {
  M() {printf("M<T*>\n");}
  T* x;
};

template <typename T, typename E>
struct N ;

template <> //全特化
struct N<int, char> {
  N() {
    printf("N<int, char>\n");
  }
};

template <typename E>//部分特化
struct N<int, E> {
  N() {
    printf("N<int, E>\n");
  }
};

template <typename E>
struct N<int, E&> {
  N() {
    printf("N<int, E*>\n");
  }
};
template <typename E>
struct N<int, const E&> {
  N() {
    printf("N<int, E*>\n");
  }
};
template <typename E>
struct N<int, E*> {
  N() {
    printf("N<int, E*>\n");
  }
};
template <typename E>
struct N<int, const E*> {
  N() {
    printf("N<int, E*>\n");
  }
};

template <typename T, int L>
struct Stack;

template <typename T>
struct Stack<T, 10> {
  Stack() {
    printf("Stack<T, 10>\n");
  }
};

template <typename T>
struct Stack<T, 20> {
  Stack() {
    printf("Stack<T, 20>\n");
  }
};

template <typename T>
void ss(T x) {
  printf("ss<T>\n");
}

//template <typename T>
//void ss<T*>(T x) {
//  printf("ss<T*>\n");
//}



//template <>
//struct M<int> {
//  M(){
//    printf("M<int>\n");
//  }
//  int x{};
//  void show() const;
//};
//void M<int>::show() const{ printf("%d\n",x); }
int main(int argc, char *argv[]) {

  uint8_t a = 11100; //11100
  uint8_t b =3;  //11000

  //C99 <stdint.h>
  uint8_t c = a & b;
  printf("%u\n", c);

  //N<int, char>n;
  //N<int, int>x;
  //N<int, int*>y;
  //M<int > m;
  //m.show();
  //M<int *> p;
  //printf("%p\n",p.x);
  
  return 0;
}


//template <typename T>
//T max(T &i, T &b) {
//  return i > b ? i: b;
//}
//template <>
//const char *max(const char * &i, const char * &b) {
//  printf("max<> const char *\n");
//  if (strcmp(i,b) > 0) 
//    return i;
//  else
//    return b;
//}
//template <>
//double max<double>(double &i, double &b) {
//  printf("max<>double const char *\n");
//  return 0;
//}
//const char *max(const char * &i, const char * &b) {
//  printf("max const char *\n");
//  if (strcmp(i,b) > 0) 
//    return i;
//  else
//    return b;
//}


////const char * max(const char* &i, const char* &b) {
////  if (strcmp(i,b) > 0) 
////    return i;
////  else
////    return b;
////}

//int main(int argc, char *argv[])
//{
//  int a=3;
//  int b=6;

//  float c=3.11123;
//  float d=3.11124;

//  const char * s2 = "hello, world";
//  const char * s1 = "hello";

//  printf("%s\n", max(s1,s2));
//  //printf("%s\n", max<const char*>(s1,s2));
//  printf("%d\n", max(a,b));
//  printf("%f\n", max(c,d));
  
//  return 0;
//}
