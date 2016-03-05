// hello.cpp 
#include <iostream>
//#include <stdio.h>
#include <cstdlib>
/*void f(double val, int val2)*/
//{
  ////int x2 = 7.9;   // if val==7.9, x2 becomes 7
  ////char c2 = val2; // if val2==1025, c2 becomes 1

  ////int x3 {val};   // error : possible truncation
  ////char c3 {val2}; // error : possible narrowing

  ////char c4 {24};   // OK: 24 can be represented exactly as a char
  ////char c5 {264};  // error :264 cannot be represented as a char
  ////
/*}*/

void f() {
  int a=0;
  char c=0;
  double d=0.0;
  int buf[10] ={0};
  int *p = NULL;
  }
void fx() {
  int a{};
  char c={};
  double d{};
  int buf[10]={1,2,3,4};
  int *p {};

  printf("%d, %d, %g, %p\n",a,c,d,p);


  }

//预处理,编译,连接,加载运行
int main() {
  fx();
  //std::cout << "hello world\n" ;
  //int i=3;
  //double d=3.4;
  //std::cout << "ni hao" << "i: "
  //          << i << " double: " << d << std::endl;
  //printf("hello printf %d\n", i);

}
