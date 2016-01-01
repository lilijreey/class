/**
 * @file     x.hpp
 *           
 *
 * @author   lili <lilijreey@gmail.com>
 * @date     12/27/2015 05:10:37 PM
 *
 */


//template <typename T> 
//void swap(T &a, T &b) ;

#include <stdio.h>
template <typename T>
void swap(T &a, T &b)
{
  printf("swap template\n");
  T tmp = a;
  a = b;
  b = tmp;
}

//template <typename T>
//void swap(T &a, T &b) ;
//{
  //printf("swap template\n");
  //xxxoo(32);
  //oooxx(false);
  //T tmp = a;
  //a = b;
  //b = tmp;
//}

